#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct matrix{
    vector <vector<int>> data;
    int n,m;
    matrix(int a, int b){
        n = a;
        m = b;
        data.resize(n);
        for (int i = 0; i < n; i++){
            data[i].resize(m,0);
        }
    }

    matrix mul(matrix b){
        matrix res(n, b.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < b.m; j++){
                for (int k = 0; k < m; k++){
                    res.data[i][j] += data[i][k] * b.data[k][j];
                }
            }
        }
        return res;
    }

};

matrix power(matrix a, int n) {
    if (n == 1) {
        return a; 
    }
    else {
        matrix ret = power(a,n / 2); 
        ret = ret.mul(ret); 
        if (n % 2 == 1) {
            ret = ret.mul(a); 
        }
        return ret; 
    }
}

void print(matrix a){
    cout << "------" << endl;
    for (int i = 0; i < a.n; i++){
        for(int j = 0; j < a.m; j++){
            cout << a.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    matrix base(2,2);

    base.data[0][1] = 1;
    base.data[1][0] = 1;
    base.data[1][1] = 1;
    
    matrix a(1,2);
    a.data[0][0] = 1;
    a.data[0][1] = 1;
    
    int n; cin >> n;

    
    cout << a.mul(power(base,n - 1)).data[0][0];


    return 0;
}

/*
3 -1 1 -2 2 0

0 -4 -2 -2 2 0

0 0 2 2 2 0

0 0 0 0 0 0
*/
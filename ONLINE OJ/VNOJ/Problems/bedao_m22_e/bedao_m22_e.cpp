#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

struct matrix{
    int n, m;
    vector <vector<int>> data;

    matrix(int _n, int _m){
        n = _n;
        m = _m;
        data.resize(n);
        for (int i = 0; i < n; i++){
            data[i].resize(m);
        }
    }

};

matrix operator * (const matrix &a, const matrix &b){
    matrix c(a.n, b.m);
    for (int i = 0; i < c.n; i++){
        for (int j = 0; j < c.m; j++){
            for (int k = 0; k < a.m; k++){
                (c.data[i][j] += a.data[i][k] * b.data[k][j]) %= mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int x){
    if (x == 1){
        return a;
    }
    matrix t = pow(a, x / 2);
    if (x % 2){
        return t * t * a;
    }
    return t * t;
}

void print(matrix x){
    for (auto i: x.data){
        for (int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int cal(int n){
    matrix A(1,2);
    A.data[0][0] = 0;
    A.data[0][1] = 1;
    matrix base(2,2);
    base.data[0][0] = 0;
    base.data[0][1] = 1;
    base.data[1][0] = 1;
    base.data[1][1] = 1;
    if (n >= 1){
        base = pow(base, n);
        A = A * base;
    }
    // print(base);
    // print(A);
    return A.data[0][0];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << cal(n);

    // for (int i = 0; i <= n; i++){
    //     cout << cal(i) << endl;
    // }

    return 0;
}

/*
1 1 2 3 5
*/
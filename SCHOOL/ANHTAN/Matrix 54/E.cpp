#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mod = 1e9 + 7;

struct matrix {
    int R, C; 
    vector <vector <long long> > data;
    matrix(int _R, int _C) {
        R = _R; 
        C = _C; 
        data.resize(R); 
        for (int i = 0; i < R; i++) {
        data[i].resize(C, 0); 
        }
    }
    matrix operator *(const matrix &other) {
        matrix ret(R, other.C);
        for (int i = 0; i < R; i++) {
        for (int j = 0; j < other.C; j++) {
            long long sum = 0; 
            for (int k = 0; k < C; k++) {
            sum = (sum + (data[i][k] * other.data[k][j]) % mod) % mod; 
            }
            ret.data[i][j] = sum; 
        }
        }
        return ret;  
    }
};

matrix power(const matrix &M, int n) {
    if (n == 1) {
        return M; 
    }
    else {
        matrix ret = power(M, n / 2); 
        ret = ret * ret; 
        if (n % 2 == 1) {
        ret = ret * M; 
        }
        return ret; 
    }
}

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

const int maxN = 1e6 + 10;

int a[maxN];
int prefix[maxN];
vector <int> ans[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    matrix base(2,2);
    matrix A(1,2);
    A.data[0][0] = 1;
    A.data[0][1] = 1;
    base.data[0][0] = 0;
    base.data[0][1] = 1;
    base.data[1][0] = 1;
    base.data[1][1] = 1; 
    while(test--){
        int n, I;
        cin >> n >> I >> mod;
        matrix BASE = power(base, I - 1);
        matrix B = A * BASE;
        a[1] = B.data[0][0];
        a[2] = B.data[0][1];
        prefix[1] = a[1];
        (prefix[1] = a[1] + a[2]) %= mod;
        
        for (int i = 0; i < mod; i++){
            ans[i].clear();
        }
        int len = -1;
        vector <int> res;
        for (int i = 3; i <= n; i++){
            a[i] = add(a[i - 1], a[i - 2]);
            (prefix[i] = prefix[i - 1] + a[i]) %= mod;
            if (!ans[prefix[i]].empty()){
                res.push_back(ans[prefix[i]][0]);
                res.push_back(i);
                len = i - ans[prefix[i]][0];
                break;
            }
            ans[prefix[i]].push_back(i);
        }
        // for(int i = 1; i <= n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;
        int x = res[0];
        int y = res[1];
        cout << len << " ";
        if (!res.empty()){
            for (int i = x + 1; i <= y; i++){
                cout << i + I - 1 << " ";
            }
        }

        cout << endl;

    }
    return 0;
}

/*
2 3 5 8 4  3  7  1  8  0 
2 3 5 8 13 21 34 55 89 144
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

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
            sum = (sum + (data[i][k] * other.data[k][j]) % (mod - 1)) % (mod - 1); 
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
    return ((a + mod) - b) % (mod); 
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    matrix A(1,k);
    for (int i = 0; i < k; i++){
        cin >> A.data[0][i];
    }
    matrix base(k,k);
    for (int i = 0; i < k - 1; i++){
        base.data[i + 1][i] = 1;
    }
    for (int i = 0; i < k; i++){
        base.data[i][k - 1] = 1;
    }

    // for (int i = 0; i < k; i++){
    //     for (int j = 0; j < k; j++){
    //         cout << base.data[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (n <= k){
        cout << A.data[0][n - 1];
        return 0;
    }

    matrix BASE = power(base, n - k);
    int ans = 1;
    for (int i = 0; i < k; i++){
        ans = mul(ans, fastpow(A.data[0][i], BASE.data[i][k - 1] % (mod - 1)));
    }
    cout << ans;
    return 0;
}

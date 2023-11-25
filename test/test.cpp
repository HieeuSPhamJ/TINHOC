#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int f[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int k){
    if (k == 0){
        return 1;
    }
    if (k == 1){
        return n;
    }
    int t = fastpow(n, k / 2);
    t = mul(t,t);
    if (k % 2){
        t = mul(t,n);
    }
    return t;
}
int divi(int a, int b){
    return mul(a, fastpow(b,mod - 2));
}

int cal(int n, int k){
    for (int i = 1; i <= k + 1; i++){
        f[i] = f[i - 1] + fastpow(i, k);
    }
    int res = 0;
    for (int i = 1; i <= k + 1; i++){
        int p = 1;
        for (int j = 1; j <= k + 1; j++){
            if (i != j){
                p = mul(p, divi(n - i, i - j));
            }
        }
        res = add(res, mul(f[i], p));
    }
    return res;
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
    int n, k;
    cin >> n >> k;
    cout << cal(n, k);
    return 0;
}
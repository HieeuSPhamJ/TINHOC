#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 998244353;

int fastpow(int nu, int a){
    if (a == 1){
        return nu;
    }
    if (a == 0){
        return 1;
    }
    int t = fastpow(nu, a / 2);
    (t *= t) %= mod;
    if (a % 2){
        (t *= nu) %= mod;
    }
    return t;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("colors.inp", "r")) {
        freopen("colors.inp", "r", stdin);
        freopen("colors.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c;
    cin >> n >> n >> c;
    cout << (c * fastpow(c - 1, n - 1)) % mod;
    return 0;
}
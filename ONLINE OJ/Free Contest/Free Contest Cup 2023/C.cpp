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

const int mod = 1e9 + 7;

int add(int a, int b){
    return (a + b) % mod;
}
int sub(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int res = mul(temp, temp);
    if (a % 2){
        return mul(res, n);
    }
    else{
        return res;
    }
}

int divi(int a, int b){
    return mul(a,fastpow(b, mod - 2));
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
    int test;
    cin >> test;
    while(test--){
        int n, k, m;
        cin >> n >> k >> m;
        if(k < n and m >= 2){
            n -= k;
            m--;
        }
        if(m % 2){
            int res = sub(fastpow(n, (m / 2) + 1), fastpow(n - 1, (m / 2) + 1));
            cout << divi(res, fastpow(n, (m / 2) + 1)) << endl;
        }
        else{
            int tu1 = mul(fastpow(n, (m - 1) / 2 + 1),(n + k));
            int tu2 = mul(fastpow(n - 1, (m - 1) / 2 + 1), (n + k - 1));
            cout << divi(sub(tu1, tu2), mul(fastpow(n, (m - 1) / 2 + 1), (n + k))) << endl;
        }
    }
    return 0;
}
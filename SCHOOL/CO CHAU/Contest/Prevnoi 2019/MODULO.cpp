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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("MODULO.inp", "r")) {
        freopen("MODULO.inp", "r", stdin);
        freopen("MODULO.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[2];
    cin >> a[0] >> a[1];
    int n, k;
    cin >> n >> k;
    int mod = 1 << n;
    for (int mask = 0; mask < (1 << n); mask++){
        int rem = 0;
        for (int i = 0, base = 1; i < n; i++){
            int c = mask & (1 << i);
            rem += a[(c != 0)] * base;
            rem %= mod;
            (base *= 10) %= mod;
        }
        if (rem == k){
            for (int i = n - 1; i >= 0; i--){
                int c = mask & (1 << i);
                cout << a[(c != 0)];
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
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

ii a[1000];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
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
    for (int i = 0; i < n; i++){
        cin >> a[i].fi;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i].se;
    }
    double res = 1e18;
    for (int mask = 0; mask <= (1 << n); mask++){
        if (__builtin_popcount(mask) != k){
            continue;
        }
        double tu1 = 0;
        double mau1 = 0;
        double tu2 = 0;
        double mau2 = 0;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                tu1 += a[i].se;
                mau1 += a[i].fi;
            }
            else{
                tu2 += a[i].se;
                mau2 += a[i].fi;
            }
        }
        res = min(res, (tu1 / mau1) * (tu2 / mau2));
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}
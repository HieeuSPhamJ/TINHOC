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

bool cmp(ii a, ii b){
    return a.fi * b.se < b.fi * a.se;
}

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
    vector <ii> ls;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }

    ii res = {0,1};

    for (int mask = 1; mask < (1 << n); mask++){
        if (__builtin_popcount(mask) != k){
            continue;
        }
        ii tres = {0,0};
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                tres.fi += ls[i].fi;
                tres.se += ls[i].se;
                // cout << ls[i].fi << " " << ls[i].se << endl;
            }
        }
        if (cmp(res, tres)){
            // cout << bitset<5>(mask) << endl;
            // for (int i = 0; i < n; i++){
            // if (mask & (1 << i)){
            //     cout << ls[i].fi << " " << ls[i].se << endl;
            // }
        // }
            res = tres;
        }
    }

    // int g = __gcd(res.fi, res.se);

    // res.fi /= g;
    // res.se /= g;

    cout << res.fi << " " << res.se << endl;
    return 0;
}
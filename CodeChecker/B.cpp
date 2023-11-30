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
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int w, c;
        cin >> w >> c;
        ls.push_back({c,w});
    }

    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        int s = 0;
        int w = 0;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                s += ls[i].fi;
                w += ls[i].se;
            }
        }
        if (w <= k){
            if (res < s){
                res = s;
                // cout << bitset<5>(mask) << " " << w << " " << s << endl;
            }
        }
    }
    cout << res << endl;
    return 0;
}
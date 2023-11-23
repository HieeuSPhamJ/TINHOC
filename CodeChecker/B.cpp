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
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair<ii,int>> ls;
    for (int i = 1; i <= m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        ls.push_back({{l,r}, x});
    }
    int res = 1e18;

    for (int mask = 0; mask < (1 << m); mask++){
        vector <int> mk(n + 2);
        int cost = 0;
        for (int i = 0; i < m; i++){
            if (mask & (1 << i)){
                mk[ls[i].fi.fi]++;
                mk[ls[i].fi.se + 1]--;
                cost += ls[i].se;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            mk[i] += mk[i - 1];
            if (mk[i]){
                cnt++;
            }
        }
        if (cnt >= k){
            res = min(res, cost);
        }
    }

    if (res == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}
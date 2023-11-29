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
        int m;
        cin >> m;
        int t;
        cin >> t;
        vector <ii> ts;
        for (int j = 1; j <= m; j++){
            int x, y;
            cin >> x >> y;
            ts.push_back({x,y});
        }
        int s = 0;
        for (int i = 0; i < m; i++){
            s += (ts[i].fi * ts[(i + 1) % m].se) - (ts[i].se * ts[(i + 1) % m].fi);
        }
        ls.push_back({abs(s),t});
    }
    ls.push_back({0,0});
    sort(all(ls));
    int res = 0;
    for (int i = 1; i <= n; i++){
        unordered_map <int,int> cnt;
        for (int j = i, ma = 0; j <= n; j++){
            ma = max(ma, ++cnt[ls[j].se]);
            if (j - i + 1 - ma <= k){
                res = max(res,ls[j].fi - ls[i - 1].fi);
            }
        }
    }
    cout << res / 2 << ".";
    if (res % 2){
        cout << 5;
    }
    else{
        cout << 0;
    }
    return 0;
}
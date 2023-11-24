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

const int maxN = 1e5 + 10;

int n;

namespace sub1{
    int m;
    ii a[maxN];

    void solve(){
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi >> a[i].se;
        }
        cin >> m;
        for (int i = 1, id = 1; i <= m; i++){
            char c;
            cin >> c;
            if (c == 'B'){
                id--;
                id = max(id, 1ll);
            }
            else if (c == 'F'){
                id++;
                id = min(id, n);
            }
            else if (c == 'C'){
                int x, y;
                cin >> x >> y;
                a[id] = {x,y};
            }
            else {
                int res = 0;
                int x = 1;
                int y = 1;
                // cout << "query: " << endl;
                for (int i = 1; i <= n; i++){
                    int nx = x + a[i].fi;
                    int ny = y + a[i].se;
                    res += (x * nx <= 0) + (y * ny <= 0);
                    x = nx;
                    y = ny;
                }
                cout << res << endl;
            }
        }
    }    
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("simulation.inp", "r")) {
        freopen("simulation.inp", "r", stdin);
        freopen("simulation.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    sub1::solve();
    return 0;
}
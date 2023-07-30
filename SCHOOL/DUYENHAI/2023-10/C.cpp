#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 9;
vector<ii> adj[maxN * 2];
int vis[maxN * 2];
int n, m;
void dickcha(){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i = 1; i < 2 * maxN; i++)
    {
        vis[i] = 1e18;
    }
    vis[1] = 0;
    q.push({0, 1});
    while (q.size()){
        ii t = q.top();
        q.pop();
        if (t.fi > vis[t.se]){
            continue;
        }

        for (auto pt : adj[t.se]){
            int v = pt.fi;
            int w = pt.se;
            if (vis[v] > vis[t.se] + w){
                vis[v] = vis[t.se] + w;
                q.push({vis[v], v});
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (vis[i + n] == 1e18){
            cout << -1 << ' ';
            continue;
        }
        cout << vis[i + n] << ' ';
        
    }
}

signed main(){
    freopen("rescue.INP", "r", stdin);
    freopen("rescue.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++){
        adj[i].push_back({i + n, 0});
    }
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v + n].push_back({u + n, w});
    }
    dickcha();
}
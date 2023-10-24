#include <bits/stdc++.h>
#define ll long long
#define ld long  double
#define ull unsigned long long
#define ii pair <int, int>
#define ill pair <ll, ll>
#define ild pair <ld, ld>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define file "test"
using namespace std;
const int N = 1e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll base = 311;
const int BLOCK_SIZE = 400;
 
int n, m;
ll ans;
ll f[2][N], d[3][N];
vector <ill> adj[N];
 
void min_road(int s, int k) {
    priority_queue <ill> h;
    vector <bool> p(n + 1, 0);
    for (int i = 1; i <= n; i ++) d[k][i] = INF;
 
    h.push({0, s});
    d[k][s] = 0;
 
    while (!h.empty()) {
        int u = h.top().se; h.pop();
        if (p[u]) continue;
        p[u] = 1;
 
        for (ill e: adj[u]) {
            int v = e.fi; ll w = e.se;
            if (d[k][v] > d[k][u] + w) {
                d[k][v] = d[k][u] + w;
                h.push({-d[k][v], v});
            }
        }
    }
}
 
void dp(int s, int t) {
    priority_queue <pair <ll, ill>> h;
    vector <bool> vis(n + 1, 0);
    for (int i = 0; i <= n; i ++)
        f[0][i] = f[1][i] = d[2][i] = INF;
 
    h.push({0, {s, 0}});
    d[2][s] = 0;
 
    while (!h.empty()) {
        pair <ll, ill> tmp = h.top(); h.pop();
        ll dist = -tmp.fi;
        int u = tmp.se.fi, p = tmp.se.se;
 
        if (!vis[u]) {
            vis[u] = 1;
            f[0][u] = min(f[0][p], d[0][u]);
            f[1][u] = min(f[1][p], d[1][u]);
            for (ill e: adj[u]) {
                int v = e.fi; ll w = e.se;
                if (d[2][v] >= dist + w) {
                    d[2][v] = dist + w;
                    h.push({-d[2][v], {v, u}});
                }
            }
        }
        else if (dist == d[2][u]) {
            if (min(d[0][u], f[0][p]) + min(d[1][u], f[1][p]) > f[0][u] + f[1][u])
                continue;
            f[0][u] = min(f[0][p], d[0][u]);
            f[1][u] = min(f[1][p], d[1][u]);
        }
    }
 
    ans = min(ans, f[0][t] + f[1][t]);
}
 
int main() {
    
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    for (int i = 0; i < m; i ++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
 
    min_road(u, 0);
    min_road(v, 1);
 
    ans = d[0][v];
 
    dp(s, t);
    dp(t, s);
 
    cout << ans;
}
/*
     /\_/\ zzZ
    (= -_-)
    / >u  >u
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2 * 1e5 + 5;
const int inf = (int)1e9;
set<int> G[N];
map<int, int> dis[N];
int sz[N], pa[N], ans[N];

struct CentroidDecomposition
{
    void init(int n)
    {
        for (int i = 1; i <= n; ++i)
            G[i].clear(), dis[i].clear(), ans[i] = inf;
    }
    void addEdge(int u, int v)
    {
        G[u].insert(v);
        G[v].insert(u);
    }
    int dfs(int u, int p)
    {
        sz[u] = 1;
        for (auto v : G[u])
            if (v != p)
            {
                sz[u] += dfs(v, u);
            }
        return sz[u];
    }
    int centroid(int u, int p, int n)
    {
        for (auto v : G[u])
            if (v != p)
            {
                if (sz[v] > n / 2)
                    return centroid(v, u, n);
            }
        return u;
    }
    void dfs2(int u, int p, int c, int d)
    { // build distance
        dis[c][u] = d;
        for (auto v : G[u])
            if (v != p)
            {
                dfs2(v, u, c, d + 1);
            }
    }
    void build(int u, int p)
    {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        if (p == -1)
            p = c;
        pa[c] = p;
        dfs2(c, p, c, 0);

        vector<int> tmp(G[c].begin(), G[c].end());
        for (auto v : tmp)
        {
            G[c].erase(v);
            G[v].erase(c);
            build(v, c);
        }
    }
    void modify(int u)
    {
        for (int v = u; v != 0; v = pa[v])
            ans[v] = min(ans[v], dis[v][u]);
    }
    int query(int u)
    {
        int mn = inf;
        for (int v = u; v != 0; v = pa[v])
            mn = min(mn, ans[v] + dis[v][u]);
        return mn;
    }
} cd;


int n, f, q;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int test;
    cin >> test;
    while(test--){
        cin >> n >> f;
        cd.init(n);
        vector <int> lists;
        for (int i = 1; i < n; i++){
            int x;
            cin >> x;
            lists.push_back(x);
        }
        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            cd.addEdge(a, b);
        }
        cd.build(1, 0);
        cd.modify(f);
        int ans = 1e8;
        for (auto i: lists){
            ans = min(ans, cd.query(i));
            cout << ans << " ";
            cd.modify(i);
        }
        cout << endl;
    }
}




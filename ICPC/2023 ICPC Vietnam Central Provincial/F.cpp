#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define endl "\n"
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define sz(a) ((int)(a).size())
#define pi 3.14159265359
#define TASKNAME ""
template <typename T>
bool maximize(T &res, const T &val)
{
    if (res < val)
    {
        res = val;
        return true;
    };
    return false;
}
template <typename T>
bool minimize(T &res, const T &val)
{
    if (res > val)
    {
        res = val;
        return true;
    };
    return false;
}
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
const int MAXN = 2e5 + 9;
vector<iii> adj[MAXN];
int n, m;
int P[23][MAXN], h[MAXN], answer[MAXN], update[MAXN];
void dfs(int u, int p)
{

    if (p != -1)
        h[u] = h[p] + 1;
    else
        h[u] = 1;
    P[0][u] = p;
    answer[u] = update[u];
    for (auto pt : adj[u])
    {
        int v = pt.fi;
        if (v == p)
            continue;
        dfs(v, u);
        answer[u] += answer[v];
    }
}
void upd(int u, int v)
{

    if (h[u] < h[v])
        swap(u, v);
    int tmpu = u;
    int tmpv = v;
    for (int i = 20; i >= 0; i--)
    {
        if (P[i][u] != -1 and h[P[i][u]] >= h[v])
        {
            u = P[i][u];
        }
    }
    if (u == v)
    {
        update[u]--;
        update[tmpu]++;
        return;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (P[i][u] != -1 and P[i][v] != -1 and P[i][u] != P[i][v])
        {
            u = P[i][u];
            v = P[i][v];
        }
    }
    int lca = P[0][u];
    update[lca] -= 2;
    update[tmpu]++;
    update[tmpv]++;
}
int res = 0;
void getans(int u, int p)
{
    for (auto pt : adj[u])
    {
        int v = pt.fi;
        if (v != p)
        {
            getans(v, u);
            res += min(pt.se.se, answer[v] * pt.se.fi);
        }
    }
}
main()
{
    // freopen(TASKNAME".inp","r",stdin);
    // freopen(TASKNAME".out","w",stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, v, u;
        cin >> a >> b >> v >> u;
        ii w = {v, u};
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dfs(1, -1);
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (P[i - 1][j] == -1)
                P[i][j] = -1;
            else
                P[i][j] = P[i - 1][P[i - 1][j]];
        }
    }
    for (int i = n; i >= 2; i--)
    {
        upd(i, i - 1);
    }
    dfs(1, -1);
    getans(1, -1);
    cout << res << endl;
}
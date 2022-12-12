//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second

using namespace std;
typedef pair <int, int> ii;
const long long oo = 1e18 + 3;
const long long mod = 1e9 + 7; // 998244353
const int N = 1e3 + 3;
struct edge
{
    int to;
    int rev;
    long long flow;
    long long cap;
};

int n, m, s, t;
long long dist[N];
int work[N];
vector <edge> g[N];

void addedge(int a, int b, int w){
    g[a].push_back({b,(int)g[b].size(), 0, w});
    g[b].push_back({a,(int)g[a].size(), 0, 0});
}

bool bfs()
{
    queue <int> q;
    for (int i = 1; i <= n; ++ i)
    {
        dist[i] = -1;
    }
    dist[s] = 0;
    q.push(s);
    int u, v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (edge e : g[u])
        {
            v = e.to;
            if (dist[v] < 0 && e.flow < e.cap)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] > 0;
}

long long dfs(int u, long long f)
{
    if (u == t)
    {
        return f;
    }
    int v;
    long long df;
    for (int &k = work[u]; k < g[u].size(); ++ k)
    {
        edge &e = g[u][k];
        v = e.to;
        if (dist[v] == dist[u] + 1 && e.flow < e.cap)
        {
            df = dfs(v, min(e. cap - e.flow, f));
            if (df > 0)
            {
                e.flow += df;
                g[v][e.rev].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

void solve()
{
    long long res = 0, del;
    while (bfs())
    {
        for (int i = 1; i <= n; ++ i)
        {
            work[i] = 0;
        }
        while (del = dfs(s, oo))
        {
            // cout << "*" << del << endl;
            res += del;
        }
    }
    cout << res;
}

int main()
{
//   freopen (taskname".inp", "r", stdin);
//   freopen (taskname".out", "w", stdout);

    // freopen ("test.inp", "r", stdin);
    // freopen ("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s >> t;
    int u, v;
    long long z;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> u >> v >> z;
        addedge(u, v, z);
    }
    solve();
    return 0;
}



//          ¯\ /¯                                                         ▄
//          [O.o]      ▄   ▄                                             ██▌
//         //)..)   ▄▄ █▀█▀█        ♥♥            █   █              ▄▄███▀
//  ╔♫═╗╔╗  -"--"- █ █▌█▄█▄█      █♥▄▄♥█      ▄█▄ █▀█▀█ ▄█▄         █████ ▄█
//  ╚╗╔╝║║♫═╦╦╦╔╗  █    ███   ██╗ ██████╗ ██╗▀▀████▄█▄████▀▀      ▄██▄█████▀
//  ╔╝╚╗♫╚╣║║║║╔╣  █   ████╗ ██╔╝██╔═══██╗██║   ██▀█▀█▀         ▄█████████
//  ╚═♫╝╚═╩═╩♫╩═╝   ▀▀▀███████╔╝ ██║▌ ▌██║██║   ██║              ▄███████▌
//      ▄▄ ▄▄▀▀▄▀▀▄    ▀  ███╔╝  ██║ ═ ██║██║   ██║            ▄█████████
//     ███████   ▄▀        ██║   ╚██████╔╝╚██████╔╝         ▄███████████▌
//     ▀█████▀▀▄▀          ╚═╝    ╚═════╝  ╚═════╝    ▄▄▄▄██████████████▌
//       ▀█▀  █                █                  ▄▄███████████████████▌
//           ▐██   ▄███████▄  ██▌               ▄██████████████████████▌
//           ████████████████████              ████████████████████████
//          █▐ ▀▀████████████▀▀        █     ▐██████████▌ ▀▀███████████
//          ▌▐  ██▄▀██████▀▄██        ▐██   ▄██████████▌         ▀██▐█▌
//         ▐┼▐  █▄═o═▄██▄═O═▄█         ██████ █████████           ▐█▐█▌
//         ▐┼▐  ██████████████          ▀▀▀▀   ██████▀            ▐█▐█▌
//         ▐▄▐████ ▀▐▐▀█ █ ▌▐██▄                █████▌            ▐█▐█▌
//           █████          ▐███▌               ███▀██             █ █▌
//           █▀▀██▄█ ▄   ▐ ▄███▀               ▐██   ██        ▄▄████████▄
//           █  ███████▄██████                 ██▌    █▄      ▄███████████████████
//              ██████████████                 ▐██     ██▄▄███████████████████████
//              █████████▐▌██▌                  ▐██  ▄████████████████████████████
//              ▐▀▐ ▌▀█▀ ▐ █               ▄▄█████████████████████████████████████
//                    ▐    ▌        ▄▄████████████████████████████████████████████
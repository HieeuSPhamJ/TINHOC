#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
int dist[1003][1003];
int minn(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
int maxx(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int bfs(int n, int m, int d)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dist[i][j] = inf;
        }
    }
    int ans = inf;
    queue<ii> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        int f1 = q.front().first;
        int f2 = q.front().second;
        // cout<<f1<<' '<<f2<<endl;
        q.pop();
        if (f1 < n && dist[n][f2] > dist[f1][f2] + 1)
        {
            dist[n][f2] = dist[f1][f2] + 1;
            q.push({n, f2});
        }
        if (f2 < m && dist[f1][m] > dist[f1][f2] + 1)
        {
            dist[f1][m] = dist[f1][f2] + 1;
            q.push({f1, m});
        }

        // f2 ---> f1
        int need = n - f1, give = f2;
        if (f2 > 0 && f1 < n && dist[f1 + minn(need, give)][f2 - minn(need, give)] > dist[f1][f2] + 1)
        {
            int x1 = f1 + minn(need, give), x2 = f2 - minn(need, give);
            dist[x1][x2] = dist[f1][f2] + 1;
            q.push({x1, x2});
        }
        need = m - f2, give = f1;
        if (f1 > 0 && f2 < m && dist[f1 - minn(need, give)][f2 + minn(need, give)] > dist[f1][f2] + 1)
        {
            int x1 = f1 - minn(need, give), x2 = f2 + minn(need, give);
            dist[x1][x2] = dist[f1][f2] + 1;
            q.push({x1, x2});
        }

        if (f1 > 0 && dist[0][f2] > dist[f1][f2] + 1)
        {
            dist[0][f2] = dist[f1][f2] + 1;
            q.push({0, f2});
        }
        if (f2 > 0 && dist[f1][0] > dist[f1][f2] + 1)
        {
            dist[f1][0] = dist[f1][f2] + 1;
            q.push({f1, 0});
        }
    }
    if (m >= d)
    {
        for (int i = 0; i <= n; i++)
        {
            ans = min(ans, dist[i][d]);
            // cout<<dist[i][d]<<' '<<i<<' '<<d<<endl;
        }
    }
    if (n >= d)
    {
        for (int i = 0; i <= m; i++)
        {
            // cout<<dist[d][i]<<' '<<d<<' '<<i<<endl;
            ans = min(ans, dist[d][i]);
        }
    }
    return ans;
}
signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    int n, m, d, t;
    cin >> t;
    while (t--)
    {
        int n, m, d, g;
        cin >> n >> m >> d;

        if ((d > n && d > m))
            cout << -1 << endl;
        else if (d == n || d == m)
            cout << 1 << endl;
        else
        {
            int ans = bfs(n, m, d);
            if (ans == inf)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }
}
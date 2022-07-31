#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1003, inf = 1e18;
int n, m, S, T;
int d[N], c[N][N], f[N][N];
int dfs[N], t = 0;
vector<int> adj[N];

bool bfs(int S, int T) {
    memset(d, 0, sizeof d);
    queue<int> qu;
    qu.push(S);
    d[S] = 1;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        if (u == T)
            return true;
        for (int v : adj[u])
            if (!d[v] && f[u][v] < c[u][v]) {
                qu.push(v);
                d[v] = d[u] + 1;
            }
    }
    return false;
}

int visit(int u, int Min) {
    if (u == T)
        return Min;
    if (dfs[u] != t)
        dfs[u] = t;
    else
        return 0;

    for (int v : adj[u])
        if (f[u][v] < c[u][v])
            if (dfs[v] != t && d[v] == d[u] + 1)
                if (int x = visit(v, min(Min, c[u][v] - f[u][v]))) {
                    f[u][v] += x;
                    f[v][u] -= x;
                    return x;
                }
    return 0;
}

signed main() {
    cin >> n;

    int vina = n + 2;
    int mobi = n + 1;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        adj[i].push_back(vina);
        c[i][vina] = inp;
    }

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        adj[mobi].push_back(i);
        c[mobi][i] = inp;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int inp;
            cin >> inp;

            adj[i].push_back(j);
            // adj[j].push_back(i);
            c[i][j] = inp;
            // c[j][i] = inp;

        }
    }
    T = vina;
	S = mobi;
    // cout << "---" << endl;
    int Sum = 0;
    while (bfs(S, T)) {
        while (int x = (t++, visit(S, inf))) {
            Sum += x;
        }
    }
    cout << Sum << endl;
}
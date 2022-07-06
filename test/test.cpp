#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

int n, k;
vector<int> adj[MAX_N];
int mark[MAX_N], sizeChild[MAX_N];
long long result = 0;

void parentDFS(int node, int parent)
{
    sizeChild[node] = mark[node];
    for (auto u : adj[node])
    {
        if (u != parent)
        {
            parentDFS(u, node);
            sizeChild[node] += sizeChild[u];
        }
    }
}

int findCentroid(int node, int parent)
{
    for (auto u : adj[node])
    {
        if (u != parent)
        {
            if (sizeChild[u] * 2 > k)
            {
                return findCentroid(u, node);
            }
        }
    }
    return node;
}

void dfs(int node, int parent, int depth)
{
    if (mark[node] == 1)
    {
        result += depth;
    }
    for (auto u : adj[node])
    {
        if (u != parent)
        {
            dfs(u, node, depth + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("test.txt", "r", stdin);
    cin >> n >> k;
    k = k * 2;
    for (int i = 1; i <= k; i++)
    {
        int u;
        cin >> u;
        mark[u] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parentDFS(1, -1);
    int centroid = findCentroid(1, -1);
    result = 0;
    dfs(centroid, -1, 0);
    cout << result;
    return 0;
}
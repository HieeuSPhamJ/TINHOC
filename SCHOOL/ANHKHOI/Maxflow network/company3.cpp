#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair <int,int>
using namespace std;

const int N = 2 * 1e3 + 10;

int n, m;
vector <int> g[N];
int Start = 0, End = 405;
int f[N][N], d[N], c[N][N];
int start[N];
int a[N][N];

bool bfs()
{
  memset(d, 0, sizeof d);
  queue <int> q; q.push(Start); d[Start] = 1;
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    //cout << u << ' ';
    if(u == End) return true;
    for(int v : g[u])
    {
      if(!d[v] && f[u][v] < c[u][v])
      {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  return false;
}

int dfs(int u, int mini)
{
  //cout << u << ',' << mini << ' ';
  if(u == End) return mini;

  for(;start[u] < g[u].size(); ++start[u])
  {
    int v = g[u][start[u]];
    if(f[u][v] < c[u][v] && d[v] == d[u] + 1)
    if(int t = dfs(v, min(mini, c[u][v] - f[u][v])))
    {
      f[u][v] += t;
      f[v][u] -= t;
      return t;
    }
  }
  return 0;
}

void addEdge(int u, int v, int cap)
{
  g[u].push_back(v);
  g[v].push_back(u);
  c[u][v] = cap;
}

void resetAll(){
  for(int i = Start; i <= End; ++i) g[i].clear();
  memset(f, 0, sizeof f);
  memset(c, 0, sizeof c);
}

signed main(){
    Start = 0;
    End = 2 * 1e3 + 5;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a = i;j
        int b = i + n;
        addEdge(Start, a, 1);
        addEdge(b, End, 1);
    }
    
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        a = a;
        b = n + b;
        addEdge(a, b, 1);
    }

    int res = 0;
    while(bfs()){
        memset(start, 0, sizeof start);
        while(int t = dfs(Start, INT_MAX)) res += t;
    }
    cout << n - res << endl;
}
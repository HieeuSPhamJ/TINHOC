#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair <int,int>
using namespace std;

const int N = 450;

int n;
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

map <int, vector <ii>> lists;

int cal(int x){
    // cout << "======" << x << "=======" << endl;
    vector <ii> tempLists = lists[x];
    resetAll();
    Start = 0;
    End = 300;
    for (int i = 1; i <= n; i++){
        addEdge(Start, i, 1);
        addEdge(n + i, End, 1);
        // cout << Start << ' ' << i << ' ' << 1 << endl;
        // cout << i + n << ' ' << End << ' ' << 1 << endl;
    }

    for (auto v: tempLists){
        int x = v.fi;
        int y = v.se + n;
        addEdge(x, y, 1);
        // cout << x << ' ' << y << ' ' << 1 << endl;
    }
    int res = 0;
    while(bfs())
    {
      memset(start, 0, sizeof start);
      while(int t = dfs(Start, INT_MAX)) res += t;
    }
    return res;
}

signed main(){
    int test;
    cin >> test;
    while(test--){
        lists.clear();
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int inp;
                cin >> inp;
                lists[inp].push_back({i,j});
            }
        }
        int ans = 0;
        for (int i = -n; i <= n; i++){
            ans += cal(i);
        }
        // cout << ans << endl;
        cout << n * n - ans << endl;

    }
}
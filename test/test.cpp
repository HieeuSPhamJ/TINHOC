#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define pp pop_back()

#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 999999999

const int N = 3 * 1e3 + 5;
int n , m , source , sink;
int work[N] , dist[N];
vector < iii > ans;

struct edge
{
    int to , rev;
    int flow , cap;
};

vector < edge > g[N];
  
void addedge(int u , int v , int cap)
{
    edge a = {v , (int)g[v].size() , 0 , cap};
    edge b = {u , (int)g[u].size() , 0 , 0};
    g[u].pb(a);
    g[v].pb(b);
}

bool BFS()
{
    queue < int > q;
    memset(dist , -1 , sizeof(dist));
    q.push(source);
    dist[source] = 0;
    while(!q.empty())
    {
        int u = q.fr;
        q.pop();
        REP(source , g[u].size())
        {
            edge e = g[u][source];
            int v = e.to;
            if(dist[v] < 0 && e.flow < e.cap)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[sink] > 0;
}

int DFS(int u , int f)
{
    if(u == sink)
        return f;
    for(; work[u] < g[u].size() ; work[u]++)
    {
        edge &e = g[u][work[u]];
        int v = e.to;
        if(dist[v] == dist[u] + 1 && e.flow < e.cap)
        {
            int df = DFS(v , min(f , e.cap - e.flow));
            if(df > 0)
            {
                e.flow += df;
                g[v][e.rev].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

int maze[1010][1010];

int solve()
{
    int res = 0;
    while(BFS())
    {
        memset(work , 0 , sizeof(work));
        while(int del = DFS(source , oo))
            res += del;
    }
    return res;
}

signed main()
{
    //freopen("flow.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    source = 0;
    sink = n + m + 1;
    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        addedge(source, i, x);
        sa += x;
    }
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        addedge(n + i, sink, x);
        sb += x;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            addedge(i,j + n,1);
        }
    }
    int bru = solve();
    if (sa == sb and sa == bru){
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++){
            for (auto e: g[i]){
                if (e.to != 0 and e.flow){
                    // cout << i << " " << e.to - n << " " << e.flow << endl;
                    maze[i][e.to - n] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No";
    }
    solve();
}
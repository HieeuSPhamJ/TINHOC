#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "pp"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 5e3 + 9;
int n,m,a,b,k,g;
vector<ii> graph[MAXN];
int u,v,w,spec[MAXN],edge[MAXN][MAXN],special_edge[MAXN][MAXN],timein[MAXN],dist[MAXN];
void dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    dist[a] = k;
    pq.push({dist[a],a});
    while(!pq.empty()){
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();

<<<<<<< HEAD
        if (du > dist[u]) continue;
        for(auto pt: graph[u]){
            int v = pt.fi;
            int w = pt.se;
            int in = 0, out = 0;
            if (special_edge[u][v] or special_edge[v][u]){
                in = min(timein[v],timein[u]), out = max(timein[u],timein[v]);
                if (dist[u] < in and dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
                if (dist[u] >= out and dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
                if (dist[u] >= in and dist[u] < out and dist[v] > out + w){
                    dist[v] = out + w;
                    pq.push({dist[v],v});
                }
            }
            else{
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }

            }
        }
    }
    cout<<dist[b] - dist[a]<<endl;
}
main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    cin>>n>>m;
    cin>>a>>b>>k>>g;
    memset(edge,0x3f,sizeof(edge));
    for(int i=1;i<=g;i++){
        cin>>spec[i];
        if (i>=2) special_edge[spec[i-1]][spec[i]] = special_edge[spec[i]][spec[i-1]] = 1;
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        if (edge[u][v] == 0) edge[u][v] = edge[v][u] = w;
        else edge[u][v] = edge[v][u] = min(edge[u][v],w);
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    timein[spec[1]] = 0;
    for(int i=2;i<=g;i++){
        timein[spec[i]] = timein[spec[i-1]] + edge[spec[i]][spec[i-1]];
    }
    dijkstra();
=======
const int maxN = 2e5 + 10;

int n;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN];
int dp2[maxN];
int child[maxN];
int lvl[maxN];


void dfs(int nu, int fa){
    child[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        lvl[i] = lvl[nu] + 1;
        dfs(i, nu);
        child[nu] += child[i];
        dp[nu] += dp[i];
    }
    dp[nu] += (child[nu] - 1);
}
int cnt = 0;
void dfs2(int nu, int fa){
    cnt++;
    dp2[nu] += dp2[fa];
    if (fa != nu){
        for (auto i: adj[fa]){
            if (i == nu or lvl[i] < lvl[fa]){
                continue;
            }
            dp2[nu] += dp[i];
        }
        dp2[nu] += n - (child[nu] + 1);
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs2(i,nu);
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    dfs2(1,1);

    cout << n << endl;

    return 0;
>>>>>>> 504a6cc3a59da46aa77138bf91bb5be96c0834ff
}
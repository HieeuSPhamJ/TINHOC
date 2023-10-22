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
#define pi 3.14159265359
#define TASKNAME "mmgraph"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 5e2 + 9;
int n,m,w[MAXN];
vector<ii> g[MAXN];
int par[MAXN];

/*sub2*/
vector<ii> mst[MAXN];
int sub2[MAXN][MAXN];
struct edge{
    int u,v,w;
    bool operator < (const edge &other){
        return w < other.w;
    }
};
int root(int u){
    if (u == par[u]) return u;
    else return par[u] = root(par[u]);
}
bool unite(int u,int v){
    u = root(u);
    v = root(v);
    if (u!=v){
        par[v] = u;
        return true;
    }
    return false;
}
void dfs(int u,int p,int mx,int origin){
    sub2[origin][u] = mx;
    for(auto pt: mst[u]){
        int v = pt.fi;
        int w = pt.se;
        if (v==p) continue;
        dfs(v,u,max(mx,w),origin);
    }
}
edge edgelist[250000];
/*   */
/*  sub 3*/
int sub3[MAXN];
void solvesub3(int u){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,u});
    for(int i=1;i<=n;i++){
        sub3[i] = INF;
    }
    sub3[u] = w[u];
    while(!pq.empty()){
        int u = pq.top().se;
        int du = pq.top().fi;
        if (du > sub3[u]) continue;
        pq.pop();
        for(auto pt: g[u]){
            int v = pt.fi;
            if (sub3[v] > max(sub3[u],w[v])){
                sub3[v] = max(sub3[u],w[v]);
                pq.push({sub3[v],v});
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        if (i!=u) sum += sub3[i];
    }
    cout<<sum<<' ';
}

/*sub 4*/
int dist[MAXN][MAXN],d[MAXN][MAXN];
void sub4(int s){
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    pq.push({0,{s,s}});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = INF;
        }
    }
    dist[s][s] = 0;
    while(!pq.empty()){
        int du = pq.top().fi;
        int u = pq.top().se.fi;
        int mx = pq.top().se.se;
        pq.pop();
        if (dist[u][mx] > du) continue;
        d[s][u] = min(d[s][u], du * w[mx]);

        for(auto pt: g[u]){
            int nxtmx = mx;
            int v = pt.fi, weight = pt.se;
            if (w[nxtmx] < w[v]) nxtmx = v;
            if (dist[v][nxtmx] > max(dist[u][mx], weight )){
                dist[v][nxtmx] = max(dist[u][mx], weight );
                pq.push({dist[v][nxtmx],{v,nxtmx}});
            }
        }
    }
}

/* sub 5*/
ii vertice[MAXN];
int weight[MAXN][MAXN];
int sub5[MAXN][MAXN];
//int dist[MAXN][MAXN],d[MAXN][MAXN]
void dijk(int s,int index){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,s});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sub5[vertice[i].se][vertice[j].se] = INF;
        }
    }
    sub5[s][s] = 0;
    while(!pq.empty()){
        int du = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (du > sub5[s][u]) continue;
//        cout<<"TOP: "<<u<<' '<<du<<endl;

        for(auto pt: g[u]){
            int v = pt.fi;
            int w = pt.se;
//            cout<<s<<' '<<u<<' '<<v<<' '<<w<<endl;
            if (sub5[s][v] > max(sub5[s][u],w)){
                sub5[s][v] = max(sub5[s][u],w);
                sub5[v][s] = sub5[s][v];
                pq.push({sub5[s][v],v});
            }
        }
    }
    for(int i=index;i>=1;i--){
        for(int j=i;j>=1;j--){
            int x = vertice[i].se;
            int y = vertice[j].se;
            sub5[y][x] = min(sub5[y][x],max(sub5[s][x],sub5[s][y]));
            sub5[x][y] = sub5[y][x];
            if (sub5[x][y] < INF) d[y][x] = d[x][y] = min(d[x][y],sub5[x][y] * w[s]);
        }
    }

}
void solvesub5(){
    for(int i=1;i<=n;i++){
        vertice[i] = {w[i],i};
    }
    sort(vertice+1,vertice+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            int u = vertice[i].se;
            int v = vertice[j].se;
            if (weight[u][v] < INF) {
//                cout<<"EDGE: "<<u<<' '<<v<<' '<<weight[u][v]<<endl;
                g[u].pb({v,weight[u][v]});
                g[v].pb({u,weight[u][v]});
            }
        }
        dijk(vertice[i].se,i);
    }
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            if (j==i) continue;
            sum += d[i][j];
        }
        cout<<sum<<' ';
    }
    cout<<endl;

}
/*   */
main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    int subtask;
    cin>>subtask;
    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    memset(weight,0x3f,sizeof(weight));
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        weight[u][v] = weight[v][u] = min(weight[u][v],w);
        edgelist[i] = {u,v,w};
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    if (subtask == 1){
        for(int i=1;i<=n;i++){
            cout<<n-1<<' ';
        }
        cout<<endl;
    }
    if (subtask == 2){
        iota(par+1,par+1+n,1);
        sort(edgelist+1,edgelist+1+m);
        for(int i=1;i<=m;i++){
            int u = edgelist[i].u;
            int v = edgelist[i].v;
            int w = edgelist[i].w;
            if (unite(u,v)) {
                mst[u].pb({v,w});
                mst[v].pb({u,w});
            }
        }
        for(int i=1;i<=n;i++){
            dfs(i,-1,0,i);
            int sum = 0;
            for(int j=1;j<=n;j++){
                sum += sub2[i][j];
            }
            cout<<sum<<' ';
        }
        cout<<endl;
    }
    if (subtask == 3){
        for(int i=1;i<=n;i++){
            solvesub3(i);
        }
    }
    if (subtask == 4){
        for(int i=1;i<=n;i++){
            sub4(i);
        }
        for(int i=1;i<=n;i++){
            int sum =0;
            for(int j=1;j<=n;j++){
                sum += d[i][j];
            }
            cout<<sum<<' ';
        }
        cout<<endl;
    }
    if (subtask == 5){
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        solvesub5();
    }
}

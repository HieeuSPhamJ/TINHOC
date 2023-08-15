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
#define TASKNAME "elecsta"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 5e5 + 9;
vector<ii> g[MAXN];
int par[MAXN],ranking[MAXN];
int root(int u){
    if (par[u]==u) return u;
    else return par[u] = root(par[u]);
}
bool unite(int u,int v){
    u = root(u);
    v = root(v);
    if (u!=v){
        if (ranking[u] <= ranking[v]) swap(u,v);
        ranking[u] += ranking[v];
        par[v] = u;
        return true;
    }
    return false;
}
iii edgelist[MAXN];
int P[30][MAXN],h[MAXN],W[30][MAXN],n,m,q;
void dfs(int u,int p,int d,int prew){
    P[0][u] = p;
    h[u] = d;
    W[0][u] = prew;
    for(auto pt: g[u]){
        int v = pt.fi;
        int w = pt.se;
        if (v==p) continue;
        dfs(v,u,d+1,w);
    }
}
void build(){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            if (P[i-1][j] == -1) P[i][j] = -1;
            else {
                P[i][j] = P[i-1][P[i-1][j]];
                W[i][j] = max(W[i-1][j],W[i-1][P[i-1][j]]);
            }
        }
    }
}
int getlca(int u,int v){
    if (h[u] <= h[v]) swap(u,v);
    int maxweight = 0;
    for(int i=20;i>=0;i--){
        if (P[i][u] != -1 and h[P[i][u]] >= h[v] ){
            maxweight = max(maxweight,W[i][u]);
            u = P[i][u];
        }
    }
    if (u==v) return maxweight;
    for(int i=20;i>=0;i--){
        if (P[i][u] != -1 and P[i][v] != -1 and P[i][u] != P[i][v]){
            maxweight = max(maxweight,W[i][u]);
            maxweight = max(maxweight,W[i][v]);
            u = P[i][u];
            v = P[i][v];
        }
    }
    return max({maxweight,W[0][u],W[0][v]});
}


main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>n>>m;
    iota(par+1,par+1+n,1);
    fill(ranking+1,ranking+1+n,1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edgelist[i] = {w,{u,v}};
    }
    int mst = 0;
    sort(edgelist+1,edgelist+1+m);
    for(int i=1;i<=m;i++){
        int u = edgelist[i].se.fi;
        int v = edgelist[i].se.se;
        int w = edgelist[i].fi;
        if (unite(u,v)){
            g[u].pb({v,w});
            g[v].pb({u,w});
            mst += w;
        }
    }
    dfs(1,-1,0,0);
    build();
    cin>>q;
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int g = getlca(u,v);
        cout<<mst - g<<endl;
    }
}
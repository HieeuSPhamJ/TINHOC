#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 510;

int n, m;
vector <ii> adj[maxN];
int a[maxN];
int dist[maxN][maxN];

void dickcha(int s){
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for (int i = 1; i <= n; i++){
            dist[s][i] = 1e18;
            d[s][i] = 1e18;
    }
    q.push({0,s});
    dist[s][s] = 0;
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (dist[s][t.se] != t.fi){
            continue;
        }
        for (auto i: adj[t.se]){
            if (dist[s][i.se] > max(t.fi, i.fi)){
                dist[s][i.se] = max(t.fi, i.fi);
                q.push({dist[s][i.se],i.se});
            }
        }
    }
}

int rt[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int d[maxN][maxN];


signed main(){
    if (fopen("mmgraph.inp", "r")) {
        freopen("mmgraph.inp", "r", stdin);
        freopen("mmgraph.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    cin >> n >> m;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rt[i] = i;
        ls.push_back({a[i],i});
    }
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});   
    }

    for (int i = 1; i <= n; i++){
        dickcha(i);
    }

    sort(all(ls));

    for (auto i: ls){
        int w = i.fi;
        for (auto j: adj[i.se]){
            int u = find(i.se);
            int v = find(j.se);
            if (u == v){
                continue;
            }
            rt[u] = v;
        }
        for (int u = 1; u <= n; u++){
            for (int v = 1; v <= n; v++){
                if (find(u) == find(v)){
                    d[u][v] = min(d[u][v], dist[u][v] * d)
                }
            }
        }
    }


    
    return 0;
}
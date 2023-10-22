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
vector <int> ls;
int dist[maxN][maxN];

void dickcha(int s){
    priority_queue <pair<int,ii>, vector <pair <int,ii>>, greater <pair <int,ii>>> q;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < ls.size(); j++){
            dist[i][j] = 1e18;
        }
    }
    q.push({a[s],{s,0}});
    dist[s][0] = a[s];
    while(q.size()){
        auto t = q.top();
        q.pop();
        if (dist[t.se.fi][t.se.se] != t.fi){
            continue;
        }
        // cout << t.se.fi << " " << t.se.se << ": " << t.fi << endl;
        for (auto i: adj[t.se.fi]){
            int me = max(i.fi, t.se.se);
            if (dist[i.se][me] > max(t.fi, a[i.se])){
                dist[i.se][me] = max(t.fi, a[i.se]);
                q.push({dist[i.se][me], {i.se, me}});
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

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    // if (fopen("mmgraph.inp", "r")) {
    //     freopen("mmgraph.inp", "r", stdin);
    //     freopen("mmgraph.out", "w", stdout);
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rt[i] = i;
    }
    vector <pair <int,ii>> lse;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        lse.push_back({w,{u,v}});
        // adj[u].push_back({w,v});
        // adj[v].push_back({w,u});   
    }

    sort(all(lse));

    for (auto i: lse){
        int u = find(i.se.fi);
        int v = find(i.se.se);
        if (u == v){
            continue;
        }
        rt[u] = v;
        u = i.se.fi;
        v = i.se.se;
        int w = i.fi;
        if (ls.empty() or ls.back() != w){
            ls.push_back(w);
        }

        adj[u].push_back({ls.size() - 1,v});
        adj[v].push_back({ls.size() - 1,u});  
        // cout << u << " " << v << endl;
    }


    for (int i = 1; i <= n; i++){
        dickcha(i);
        int s = 0;
        for (int x = 1; x <= n; x++){
            if (i == x){
                continue;
            }
            int t = 1e18;
            for (int k = 0; k < ls.size(); k++){
                // cout << x << " " << ls[k] << ": " << dist[x][k] << endl;
                if (dist[x][k] != 1e18){
                    t = min(t, dist[x][k] * ls[k]);
                }
            }
            // cout << x << " " << t << endl;
            s += t;
        }
        cout << s << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

struct node{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <node> adj[maxN];
int nxt[maxN];
int dist[maxN];

void add(int a, int b, int w){
    node u = {b,adj[b].size(), 0, w};
    node v = {a,adj[a].size(), 0, 0};
    adj[a].push_back(u);
    adj[b].push_back(v);
}

bool cango(){
    for (int i = 1; i <= n; i++){
        dist[i] = 0;
    }
    queue <int> q;
    q.push(s);
    dist[s] = 1;

    while(q.size()){
        int te = q.front();
        q.pop();
        for (auto i: adj[te]){
            if (dist[i.to] == 0 and i.had < i.cap){
                dist[i.to] = dist[te] + 1;
                q.push(i.to);
            }
        }
    }
    
    return dist[t];
}

int Try(int nu, int Min){
    if (nu == t){
        return Min;
    }
    for (auto &i: adj[nu]){
        if (dist[i.to] == dist[nu] + 1 and i.had < i.cap){
            int tMin = min(Min, i.cap - i.had);
            tMin = min(tMin, Try(i.to, tMin));
            if (tMin){
                i.had += tMin;
                adj[i.to][i.rev].had -= tMin;
                return tMin;
            }
        }
    }

    return 0;
}

int dinic(){
    int res = 0;
    while(cango()){
        // cout << "With: " << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << i << ": " << dist[i] << endl;
        // }
        while(int t = Try(s,inf)){
            // cout << t << endl;
            res += t;
            // break;
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s >> t;
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a,b,w);
    }
    
    cout << dinic() << endl;

    return 0;
}
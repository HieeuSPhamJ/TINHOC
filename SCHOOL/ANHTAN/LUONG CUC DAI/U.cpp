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
    // cout << a << " " << b << " " << w << endl;
    node u = {b,(int)adj[b].size(),0,w};
    node v = {a,(int)adj[a].size(),0,0};
    adj[a].push_back(u);
    adj[b].push_back(v);
}

bool cango(){
    memset(dist, -1, sizeof(dist));
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    int check = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if (temp == t){
            check = 1;
        }
        for (auto i: adj[temp]){
            if (dist[i.to] == -1 and i.had < i.cap){
                dist[i.to] = dist[temp] + 1;
                q.push(i.to); 
            }
        }
    }

    return check;
}

int Try(int node, int Min){
    if (node == t){
        return Min;
    }
    for (auto& nu: adj[node]){
        if (dist[nu.to] == dist[node] + 1 and nu.had < nu.cap){
            int tMin = min(Min,nu.cap - nu.had);
            tMin = Try(nu.to, tMin);
            if (tMin != 0){
                nu.had += tMin;
                adj[nu.to][nu.rev].had -= tMin;
                return tMin;
            }
        }
    }
    return 0;
}

int dinic(){
    int res = 0;
    // cango();
    // for (int i = 1; i <= n; i++){
    //     cout << dist[i] << endl;
    // }
    while(cango()){
        memset(nxt, 0, sizeof(nxt));
        while(int temp = Try(s,inf)){
            res += temp;
        }
    }
    return res;
}

vector <int> ans;

void dfs(int node, int father){
    ans.push_back(node);
    dist[node] = 1;
    // for (int i = 1; i <= n; i++){
    //     cout << dist[node] << " ";
    // }
    // cout <<endl;
    // cout << node <<endl;
    for (auto e: adj[node]){
        if (e.had == e.cap or dist[e.to] == 1){
            continue;
        }
        dfs(e.to,node);
    }
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

    dinic();
    memset(dist,0,sizeof(dist));
    dfs(s,s);

    cout << ans.size() << endl;

    for (auto i: ans){
        cout << i << endl;
    }

    return 0;
}
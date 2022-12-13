#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e3 + 10;

struct edge{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <edge> adj[maxN];
int dist[maxN];
int nxt[maxN];

void add(int a, int b, int w){
    adj[a].push_back({b,(int)adj[b].size(), 0, w});
    adj[b].push_back({a,(int)adj[a].size(), 0, 0});
}

bool check(){
    queue <int> q;
    memset(dist, -1, sizeof(dist));
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for (auto i: adj[temp]){
            if (dist[i.to] == -1 and i.had < i.cap){
                q.push(i.to);
                dist[i.to] = dist[temp] + 1;
            }
        }
    }
    if (dist[t] != -1){
        return 1;
    }
    return 0;
}

int Try(int node, int Min){
    if (node == t){
        return Min;
    }
    for (; nxt[node] < adj[node].size(); nxt[node]++){
        auto& i = adj[node][nxt[node]];
        if (dist[i.to] == dist[node] + 1 and i.had < i.cap){
            int tMin = min(Min, i.cap - i.had);
            int tryNext = Try(i.to, tMin);
            if (tryNext > 0){
                i.had += tryNext;
                adj[i.to][i.rev].had -= tryNext;
                return tryNext;
            }
        }
    }
    return 0;
}

int dinic(){
    int res = 0;
    while(check()){
        memset(nxt, 0, sizeof(nxt));
        while(int temp = Try(s,inf)){
            res += temp;
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
    cin >> n >> m;
    s = 0;
    t = n * m + 1;
    return 0;
}
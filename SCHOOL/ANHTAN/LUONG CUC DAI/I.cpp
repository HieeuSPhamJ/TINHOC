#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

struct edge{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <edge> adj[maxN];
int dist[maxN];
int nxt[maxN];

void add(int a, int b, int w){
    // cout << a << " " << b << " " << w << endl;
    edge u = {b,(int)adj[b].size(),0,w};
    edge v = {a,(int)adj[a].size(),0,0};
    adj[a].push_back(u);
    adj[b].push_back(v);
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

int ans[1010][1010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    s = 0;
    t = n + m + 1;
    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        add(s, i, x);
        sa += x;
    }
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        add(n + i, t, x);
        sb += x;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            add(i,j + n,1);
        }
    }
    int bru = dinic();
    if (sa == sb and sa == bru){
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++){
            for (auto e: adj[i]){
                if (e.to != 0 and e.had){
                    // cout << i << " " << e.to - n << " " << e.had << endl;
                    ans[i][e.to - n] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No";
    }
    return 0;
}
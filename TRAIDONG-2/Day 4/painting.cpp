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
    node u = {b,(int)adj[b].size(), 0, w};
    node v = {a,(int)adj[a].size(), 0, 0};
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

int a[55][55];
int dp[55][55][55][55];

int get(int x, int y, int u, int v){
    return a[u][v] - a[u][y - 1] - a[x - 1][v] + a[x - 1][y - 1];
}

int cal(int x, int y, int u, int v){
    int &cur = dp[x][y][u][v];
    if (cur != -1){
        // cout << x << " " << y << " " << u << " " << v << ": has " << cur << endl;
        return cur;
    }
    if (x > u or y > v){
        cur = 0;
        // cout << x << " " << y << " " << u << " " << v << ": mt " << cur << endl;
        return 0;
    }
    cur = max(u - x + 1,v - y + 1);
    // cout << x << " " << y << " " << u << " " << v << ": " << cur << endl;
    if ((u - x + 1) * (v - y + 1) == get(x,y,u,v)){
        // cout << x << " " << y << " " << u << " " << v << ": full " << cur << endl;
        return cur;
    }
    

    for (int i = x; i <= u; i++){
        if (get(i,y,i,v) == 0){
            // cout << x << " " << y << " " << u << " " << v << "|" << endl;
            int t = cal(x, y, i - 1, v) + cal(i + 1, y, u, v);
            cur = min(cur, t);
        }
    }
    for (int i = y; i <= v; i++){
        if (get(x,i,u,i) == 0){
            // cout << x << " " << y << " " << u << " " << v << "|" << endl;
            int t = cal(x, y, u, i - 1) + cal(x, i + 1, u, v);
            // if (t < cur){
            //     cout << "*" << endl;
            // }
            cur = min(cur, t);
        }
    }
    // cout << x << " " << y << " " << u << " " << v << ": " << cur << endl;
    return cur;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N, S;
    cin >> K >> N >> S;
    if (K == 1){
        set <int> x,y;
        for (int i = 1; i <= S; i++){
            int a, b;
            cin >> a >> b;
            add(a,b + N,1);
        }
        for (int i = 1; i <= N; i++){
            add(0,i,1);
            add(i + N, N + N + 1, 1);
        }
        n = N + N + 1;
        s = 0;
        t = n;
        cout << dinic();
    }
    else{
        for (int i = 1; i <= S; i++){
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        // for (int i = 1; i <= N; i++){
        //     for (int j = 1; j <= N; j++){
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
                // cout << a[i][j];
            }
            // cout << endl;
        }
        // cout << get(2,2,1,3) << endl;
        memset(dp, -1, sizeof(dp));
        cout << cal(1,1,N,N) << endl;
        
    }

    return 0;
}
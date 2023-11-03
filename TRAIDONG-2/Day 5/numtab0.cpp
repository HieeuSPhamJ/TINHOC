#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a[150][150];

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
    node u = {b,(int)adj[b].size(), 0, w};
    node v = {a,(int)adj[a].size(), 0, 0};
    adj[a].push_back(u);
    adj[b].push_back(v);
    // cout << a << " " << b << " " << w << endl;
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

int b[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){   
        for (int j = 1; j <= N; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                add(i,j + N,1);
            }
        }   
    }
    for (int i = 1; i <= N; i++){
        add(0,i,1);
        add(i + N, N + N + 1, 1);
    }
    n = N + N + 1;
    s = 0;
    t = n;
    int res = dinic();
    // cout << res << endl;
    if (res == N){
        for (int i = 1; i <= N; i++){
            for (auto x: adj[i]){
                if (x.had > 0){
                    b[i] = x.to - N;
                    // cout << i << " " << x.to - N << endl;
                }
            }
        }

        vector <ii> ls;
        for (int i = N; i >= 1; i--){
            for (int j = i - 1; j >= 1; j--){
                if (b[j] > b[i]){
                    swap(b[i], b[j]);
                    ls.push_back({i,j});
                }
            }
        }
        cout << ls.size() << endl;
        for (auto i: ls){
            cout << 1 << " " << i.fi << " " << i.se << endl;
        }
    }
    else{
        cout << -1 << endl;
    }


    return 0;
}

/*
1 0 0
1 1 0
1 0 1
*/
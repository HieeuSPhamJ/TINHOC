#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 3e4 + 10;
int ans = 0;

int _n;
int _m;
int n, m, VAL, s, t;
// int cost[maxN][maxN];
// int had[maxN][maxN];
// int cap[maxN][maxN];

unordered_map <int,int> cost[maxN];
unordered_map <int,int> had[maxN];
unordered_map <int,int> cap[maxN];

vector <int> adj[maxN];
int dist[maxN];
int trace[maxN];
int a[200][200];

void add(int a, int b, int costi, int capa){
    // cout << a << " " << b << " " << costi << "," << capa << endl;
    cost[a][b] = cost[b][a] = costi;
    cap[a][b] = capa;

    adj[a].push_back(b);
    adj[b].push_back(a);

}

bool cango(){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while(q.empty() == 0){
        int te = q.front();
        q.pop();
        for (auto i: adj[te]){
            if (had[te][i] >= cap[te][i]){
                continue;
            }
            int co = cost[te][i];
            if (had[te][i] < 0){
                co = -co;
            }

            if (dist[i] > dist[te] + co){
                dist[i] = dist[te] + co;
                q.push(i);
                trace[i] = te;
            }
        }
    }
    return dist[t] != inf;
}


void Try(){
    int now = inf;
    for (int i = t; i != s; i = trace[i]){
        int temp = -had[trace[i]][i];
        if (had[trace[i]][i] >= 0){
            temp = cap[trace[i]][i] - had[trace[i]][i];
        }
        now = min(now, temp);
        
    }

    now = min(now, VAL);

    for (int i = t; i != s; i = trace[i]){
        had[i][trace[i]] -= now;
        had[trace[i]][i] += now;
    }
    VAL -= now;
    ans += now * dist[t];
    // cout << VAL << endl;
    if (!VAL){
        cout << abs(ans) << endl;
        // for (int i = 1; i <= n / 2; i++){
        //     for (int j = 1; j <= n / 2; j++){
        //         if (had[i + n / 2][j] > 0){
        //             cout << i << " " << j << endl;
        //         }
        //     }
        // }
        // cout << 0 << " " << 0 << " " << 0 << endl;
        exit(0);
    }
}

void minCost(){
    while(cango()){
        Try();
    }
}


int cord(ii x){
    return (x.fi - 1) * _m + x.se;
}

int base;

void add(ii x, ii y){
    if (y.fi > _n or y.se > _m){
        return;
    }
    add(cord(x) + base, cord(y), 0, 4);
    add(cord(x), cord(y), 0, 4);
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> _n >> _m;
    for (int i = 1; i <= _n; i++){
        for (int j = 1; j <= _m; j++){
            cin >> a[i][j];
            a[i][j] = -a[i][j];
        }
    }
    base = _n * _m;
    n = 3 * base;
    s = 1;
    t = 2 * base;
    VAL = 4;
    for (int i = 1; i <= _n; i++){
        for (int j = 1; j <= _m; j++){
            add(cord({i,j}), cord({i,j}) + base, a[i][j], 1);
            add(cord({i,j}), cord({i,j}) + 2 * base, 0, 3);
            add(cord({i,j}) + 2 * base, cord({i,j}) + 1 * base, 0, 3);
            add({i, j}, {i + 1, j});
            add({i, j}, {i, j + 1});
        }
    }
    minCost();
    cout << "=====" << endl;
    return 0;
}
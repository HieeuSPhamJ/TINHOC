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

const int maxN = 1e5 + 10;

vector <ii> adj[maxN];
int dist[5][maxN];
vector <int> path[maxN];
int mk[maxN];
int cntin[maxN];

void dickcha(int s, int type){
    for (int i = 1; i < maxN; i++){
        dist[type][i] = 1e18;
        path[i].clear();
    }
    priority_queue <ii, vector <ii>, greater <ii>> q;
    dist[type][s] = 0;
    q.push({0,s});
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (dist[type][t.se] != t.fi){
            continue;
        }
        for (auto i: adj[t.se]){
            if (dist[type][i.se] > t.fi + i.fi){
                dist[type][i.se] = t.fi + i.fi;
                path[i.se].clear();
                path[i.se].push_back(t.se);
                q.push({dist[type][i.se], i.se});
            }
            else if (dist[type][i.se] == t.fi + i.fi){
                path[i.se].push_back(t.se);
            }   
        }
    }
}

void dfs(int nu){
    cntin[nu]++;
    mk[nu] = 1;
    cout << nu << endl;
    for (auto i: path[nu]){
        if (mk[i] == 0){
            dfs(i);
        }
    }
}

int dp[maxN];

void solve(int t){
    dickcha(S,1);
    dickcha(T,2);
    dfs(t);
    for (int i = 1; i < maxN; i++){
        dp[i] = 1e18;
    }
    queue <int> q;
    q.push(t);
    dp[t] = dist[1][t];
    cntin[t]--;
    while(q.size()){
        int te = q.front();
        q.pop_back();
        for (auto i: path[te]){
            cntin[i]--;
            dp[i] = min(dist[1][i], dp[t]);
            if (cntin[i] == 0){
                q.push(i);
            }
        }
    }

    int res = 1e18;

    for (int i = 1; i <= n; i++){
        res = min(res, dp[i] + dist[2][i]);
    }

    cout << res << endl;
}

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
    int n, m, s, t, S, T;
    cin >> n >> m;
    cin >> s >> t >> S >> T;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    dickcha(s,0);
    solve(t);



    return 0;
}
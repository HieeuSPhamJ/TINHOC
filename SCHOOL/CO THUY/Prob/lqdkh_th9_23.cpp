#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int n, m, C;
vector <int> adj[maxN];
int cost[maxN];
int vis[maxN][maxN];

int dickcha(){
    priority_queue <pair<int,ii>> q;
    q.push({0,{0,1}});
    vis[0][1] = 0;
    int cnt = 10;
    while(q.size()){
        pair<int,ii> t = q.top();
        q.pop();
        if (vis[t.se.fi][t.se.se] != t.fi){
            continue;
        }
        if (t.fi < 0 or t.se.fi >= 1000){
            continue;
        }
        // cout << t.fi << " " << t.se.fi << " " << t.se.se << ": " << endl;
        for (auto nu: adj[t.se.se]){
            int ti = t.se.fi + 1;
            int w = t.fi + cost[nu] - C * (ti * ti - (ti - 1) * (ti - 1));
            if (vis[ti][nu] < w){
                vis[ti][nu] = w;
                q.push({vis[ti][nu], {ti, nu}});
                // cout << " " << vis[ti][nu] << " " << ti << " " << nu << endl;
            }

        }
        // if (cnt-- == 0){
        //     break;
        // }
    }
    int res = 0;
    for (int t = 1; t < maxN; t++){
        // for (int i = 1; i <= n; i++){
        //     cout << i << ": " << vis[t][i] << endl;
        // }
        res = max(res,vis[t][1]);
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> C;
    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << dickcha();

    return 0;
}
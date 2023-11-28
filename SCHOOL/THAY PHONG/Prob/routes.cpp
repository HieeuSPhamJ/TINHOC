#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 410;

int n, m;

int vis[maxN][maxN];
unordered_set <int> adj[maxN];
unordered_set <int> iAdj[maxN];

void bfs(){
    queue <ii> q;
    q.push({1,1});
    memset(vis,-1,sizeof(vis));
    vis[1][1] = 0;
    while(q.size()){
        ii t = q.front();
        q.pop();
        for (auto i: adj[t.fi]){
            for (auto j: iAdj[t.se]){
                if (i == j){
                    if (i == n){
                        vis[i][j] = vis[t.fi][t.se] + 1;
                        return;
                    }
                }
                else{
                    if (vis[i][j] == -1){
                        vis[i][j] = vis[t.fi][t.se] + 1;
                        q.push({i,j});
                    }
                }
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                iAdj[i].insert(j);
            }
        }
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        if (iAdj[a].find(b) != iAdj[a].end()){
            iAdj[a].erase(iAdj[a].find(b));
        }
        if (iAdj[b].find(a) != iAdj[b].end()){
            iAdj[b].erase(iAdj[b].find(a));
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << endl;
    //     for (auto x: adj[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    //     for (auto x: iAdj[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    bfs();

    cout << vis[n][n];
    return 0;
}
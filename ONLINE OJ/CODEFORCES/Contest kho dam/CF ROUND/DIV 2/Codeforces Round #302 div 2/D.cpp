#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3010;

vector <int> adj[maxN];

int vis[maxN];
int mk[maxN][maxN];
int dist[maxN][maxN];

void bfs(int s){
    memset(vis,-1,sizeof(vis));
    queue <int> q;
    q.push(s);
    vis[s] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            if (vis[i] == -1){
                vis[i] = vis[t] + 1;
                q.push(i); 
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
    int n, m;
    cin >> n >> m;
    vector <ii> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int t1[4];
    int t2[4];
    cin >> t1[0] >> t1[1] >> t1[2];
    cin >> t2[0] >> t2[1] >> t2[2];

    for (int i = 1; i <= n; i++){
        bfs(i);
        for (int j = 1; j <= n; j++){
            dist[i][j] = vis[j];
        }
    }

    int ans = 1e18;
    if (dist[t1[0]][t1[1]] <= t1[2] and dist[t2[0]][t2[1]] <= t2[2]){
        ans = dist[t1[0]][t1[1]] + dist[t2[0]][t2[1]];
    }
    for (int i = 0; i <= 1; i++){
        for (int j = 0; j <= 1; j++){
            // cout << t1[i] << " and " << t2[j] << ":" << endl;
            for (int x = 1; x <= n; x++){
                for (int y = 1; y <= n; y++){
                    int d1 = dist[t1[i]][x] + dist[x][y] + dist[y][t1[!i]];
                    int d2 = dist[t2[j]][x] + dist[x][y] + dist[y][t2[!j]];
                    // cout << x << " " << y << endl;
                    if (d1 <= t1[2] and d2 <= t2[2]){
                        ans = min(ans, d1 + d2 - dist[x][y]);
                    }
                }
            }
        }
    }
    
    if (ans > m){
        cout << -1 << endl;
        return 0;
    }
    cout << m - ans << endl;
    return 0;
}
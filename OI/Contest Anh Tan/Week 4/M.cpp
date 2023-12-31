#include"bits/stdc++.h"
//#define double long double
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define iiii pair<int,pair<int,ii>>
#define cost1 fi
#define cost2 se.fi
#define turn se.se.fi
#define node se.se.se
using namespace std;

const int maxN = 44444 + 10;
const int inf = 1e18 + 7;

int n, m, k;
int vis[maxN][5][180];
int vis2[maxN];
vector <ii> adj[maxN];
int final[maxN];

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
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    // memset(vis, 0x3f, sizeof(vis));
    // memset(final, 0x3f, sizeof(final));
    for (int i = 0; i <= n; i++){
        final[i] = inf;
        for (int t = 0; t <= k; t++){
            for (int j = 0; j < 180; j++){
                vis[i][t][j] = inf;
            }
        }
    }
    priority_queue <iiii,vector<iiii>, greater<iiii>> q;
    vis[1][0][0] = 0;
    q.push({0,{0,{0,1}}});
    while(q.size()){
        iiii t = q.top();
        q.pop();
        if (vis[t.node][t.turn][t.cost2] != t.cost1){
            continue;
        }
        // cout << "With: " << t.node << " " << t.turn << " " << t.cost2 << " " << t.cost1 << endl;
        for (auto i: adj[t.node]){
            int w1 = t.cost1;
            int w2 = t.cost2 + i.fi;
            if ((t.turn + 1) % k == 0){
                w1 = w1 + pow(w2,k);
                w2 = 0;
            }
            int &cvis = vis[i.se][(t.turn + 1) % k][w2];
            iiii nu = {w1,{w2,{(t.turn + 1) % k, i.se}}};
            if (cvis > w1 and w1 + pow(w2,k) < final[nu.node]){
                cvis = w1;
                if (nu.turn == k){
                    final[nu.node] = w1;
                }
                q.push(nu);
                // if (t.)
                // cout << " " << nu.node << " " << nu.turn << " " << nu.cost2 << " " << cvis << endl;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (vis[i][0][0] >= inf){
            cout << -1 << " ";
            continue;
        }
        cout << vis[i][0][0] << " ";
    }

    return 0;
}
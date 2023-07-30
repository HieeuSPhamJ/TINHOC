#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 510;

int n, k, m;
int a[maxN][maxN];
int dist[20][20];
int vis[maxN][maxN];
ii d[] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int dpmin[20][1 << 13];
int mincost[1 << 13];
int dp[1 << 13];
int weight[1 << 13];

bool check(ii nu){
    if (min(nu.fi, nu.se) <= 0 or max(nu.fi, nu.se) > n or a[nu.fi][nu.se] == -1){
        return 0;
    }
    return 1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char x;
            cin >> x;
            if (x == '#'){
                a[i][j] = -1;
            }
            else if (x == '+'){
                a[i][j] = 1;
            }
        }
    }

    vector <pair <ii,int>> ls;

    for (int i = 1; i <= k; i++){
        int x, y, w;
        cin >> x >> y >> w;
        ls.push_back({{x,y}, w});
    }

    for (int i = 0; i < k; i++){
        priority_queue <pair<int,ii>, vector <pair<int,ii>>, greater<pair<int,ii>>> q;
        for (int x = 1; x <= n; x++){
            for (int y = 1; y <= n; y++){
                vis[x][y] = 1e18;
            }
        }
        q.push({0,ls[i].fi});
        vis[ls[i].fi.fi][ls[i].fi.se] = 0;

        // cout << "With: " << i << endl;
        while(q.size()){
            auto t = q.top();
            q.pop();
            if (vis[t.se.fi][t.se.se] != t.fi){
                continue;
            }
            for (int di = 0; di < 4; di++){
                ii nu = t.se;
                nu.fi += d[di].fi;
                nu.se += d[di].se;
                if (check(nu)){
                    if (vis[nu.fi][nu.se] > t.fi + a[nu.fi][nu.se]){
                        // cout << nu.fi << " " << nu.se << ": " << t.fi + a[nu.fi][nu.se] << endl;
                        vis[nu.fi][nu.se] = t.fi + a[nu.fi][nu.se];
                        q.push({vis[nu.fi][nu.se], nu});
                    }
                }
            }
        }

        for (int j = 0; j < k; j++){
            dist[i][j] = vis[ls[j].fi.fi][ls[j].fi.se];
        }
        dist[i][i] = vis[1][1];
    }

    // for (int i = 0; i < k; i++){
    //     for (int j = 0; j < k; j++){
    //         cout << i << " " << j << ": " << dist[i][j] << endl;
    //     }
    // }

    for (int mask = 1; mask <= (1 << k); mask++){
        for (int i = 0; i < k; i++){
            if (mask & (1 << i)){
                weight[mask] += ls[i].se;
            }
            dpmin[i][mask] = 1e18;
        }
        mincost[mask] = 1e18;
        dp[mask] = 1e18;
    }

    for (int i = 0; i < k; i++){
        dpmin[i][1 << i] = dist[i][i];
        // cout << i << " " << dpmin[i][1 << i] << endl;
    }

    for (int mask = 1; mask <= (1 << k); mask++){
        for (int i = 0; i < k; i++){
            if (mask & (1 << i)){
                int cur = dpmin[i][mask];
                for (int j = 0; j < k; j++){
                    if ((mask & (1 << j)) == 0){
                        dpmin[j][mask | (1 << j)] = min(dpmin[j][mask | (1 << j)], cur + dist[i][j]);
                    }
                }
            }
            // cout << bitset<4>(mask) << " " << i << ": " << dpmin[i][mask] + dist[i][i] << endl;
            mincost[mask] = min(mincost[mask], dpmin[i][mask] + dist[i][i]);
        }
    }

    // for (int mask = 0; mask < (1 << k); mask++){
    //     cout << bitset<4>(mask) << " " << mincost[mask] << endl;
    // }
    dp[0] = 0;
    for (int mask = 1; mask < (1 << k); mask++){
        int &res = dp[mask];
        // cout << bitset<4>(mask) << ": " << endl;
        for (int pmask = mask; pmask; pmask = mask & (pmask - 1)){
            if (weight[pmask] <= m){
                // cout << bitset<4>(pmask) << " " << dp[mask xor pmask] + mincost[pmask] << endl;
                res = min(res, dp[mask xor pmask] + mincost[pmask]);
            }
        }
        // cout << dp[mask] << endl;
    }
    cout << dp[(1 << k) - 1] << endl;

    return 0;
}
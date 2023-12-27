#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int n, m;

int a[20][20];
ii d[] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
int dist[20][20];
int dp[20][1 << 16];
int res = 1e18;

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
    while(1){
        cin >> m >> n;
        if (n * m == 0){
            return 0;
        }
        vector <ii> ls;
        ii s = {-1,-1};
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char c;
                cin >> c;
                a[i][j] = 0;
                if (c == 'o'){
                    s = {i,j};
                    continue;
                }
                if (c == 'x'){
                    a[i][j] = 1;
                    continue;
                }
                if (c == '*'){
                    ls.push_back({i,j});
                    continue;
                }
            }
        }
        ls.push_back(s);
        reverse(all(ls));
        int k = ls.size();
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        map <ii, int> vis;
        for (int i = 0; i < k; i++){
            queue <ii> q;
            q.push(ls[i]);
            vis.clear();
            vis[ls[i]] = 1;
            while(q.size()){
                ii t = q.front();
                q.pop();
                for (int x = 0; x < 4; x++){
                    ii nu = t;
                    nu.fi += d[x].fi;
                    nu.se += d[x].se;
                    if (min(nu.fi, nu.se) < 1 or nu.fi > n or nu.se > m or a[nu.fi][nu.se] == 1){
                        continue;
                    }
                    if (vis[nu] == 0){
                        vis[nu] = vis[t] + 1;
                        q.push(nu);
                    }
                }
            }

            for (int j = 0; j < k; j++){
                dist[i][j] = vis[ls[j]];
                dist[i][j]--;
            }
        }

        // for (auto i: ls){
        //     cout << i.fi << ' ' << i.se << endl;
        // }
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                if (dist[i][j] == -1){
                    dist[i][j] = 1e18;
                }
                // cout << dist[i][j] << ' ';
            }
            // cout << endl;
        }

        for (int i = 0; i < (1 << k); i++){
            for (int j = 0; j < k; j++){
                dp[j][i] = 1e18;
            }
        }

        dp[0][1] = 0;
        for (int mask = 0; mask < (1 << k); mask++){
            for (int i = 0; i < k; i++){
                if (dp[i][mask] == 1e18){
                    continue;
                }
                // cout << i << " " << bitset<4>(mask) << ": " << dp[i][mask] << endl;
                for (int j = 0; j < k; j++){
                    if (!(mask & (1 << j))){
                        minimize(dp[j][mask | (1 << j)], dp[i][mask] + dist[i][j]);
                    }
                }
            }
        }

        res = 1e18;
        for (int i = 0; i < k; i++){
            minimize(res, dp[i][(1 << k) - 1]);
        }
        if (res == 1e18){
            cout << -1 << endl;
            continue;
        }
        cout << res << endl;
    }
    return 0;
}
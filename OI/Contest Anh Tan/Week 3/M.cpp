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

struct node{
    int t,p1,p2,p3,p4;
};

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int dp[110][110];
int a[110][110];
int grid[110][110];

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
    int n, m;
    cin >> n >> m;
    memset(a, -1,sizeof(a));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int test = 4;
    int res = 0;
    while(test--){
        memset(dp, -1,sizeof(dp));
        dp[1][1] = a[1][1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                maximize(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
                maximize(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            }
        }
        res += dp[n][m];
        ii t = {n,m};
        // memset(grid, 0, sizeof(grid));
        while(t != ii(1,1)){
            int la = dp[t.fi][t.se] - a[t.fi][t.se];
            a[t.fi][t.se] = 0;
            grid[t.fi][t.se] = 1;
            if (dp[t.fi - 1][t.se] == la){
                t.fi--;
                continue;
            }
            if (dp[t.fi][t.se - 1] == la){
                t.se--;
                continue;
            }
            // cout << t.fi << " " << t.se << " " << la << endl;
        }
        grid[1][1] = 1;
        a[1][1] = 0;
        // cout << "======" << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << grid[i][j];
        //     }
        //     cout << endl;
        // }
    }
    cout << res << endl;
    return 0;
}
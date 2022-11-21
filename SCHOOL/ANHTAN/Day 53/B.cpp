#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 600;

int dp[maxN][maxN];
int a[maxN][maxN];

ii d[]{
    {0, 1},
    {-1, 1},
    {1, 1}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            dp[i][j] = -1e18;
        }
    }
    for (int i = 1; i <= n; i++){
        dp[i][1] = a[i][1];
    }
    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            int now = dp[i][j];
            for (int k = 0; k < 3; k++){
                int x = i + d[k].fi;
                int y = j + d[k].se;
                dp[x][y] = max(dp[x][y], now + a[x][y]);
                
            }
        }
    }
    int ans = -1e18;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[i][m]);
    }

    cout << ans;
    return 0;
}
/*
9 - 1 + 8 + 7 + 5 + 6 + 7
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 100000000;

int dp[202][102][2][11];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k[3];
    cin >> n >> m >> k[0] >> k[1];
    dp[1][0][0][1] = 1;
    dp[1][1][1][1] = 1;
    for (int i = 1; i <= n + m; i++){
        for (int y = 0; y <= m; y++){
            for (int type = 0; type <= 1; type++){
                for (int last = 1; last <= k[type]; last++){
                    int now = dp[i][y][type][last];
                    // cout << i << " " << x << " " << y << " " << type << " " << last << endl;
                    // cout << "DP: " << now << endl;
                    if (now == 0){
                        continue;
                    }
                    if (type == 1){
                        (dp[i + 1][y][!type][1] += now) %= mod;
                    }
                    else{
                        (dp[i + 1][y + 1][!type][1] += now) %= mod;
                    }

                    if (type == 0){
                        (dp[i + 1][y][type][last + 1] += now) %= mod;
                    }
                    else{
                        (dp[i + 1][y + 1][type][last + 1] += now) %= mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int type = 0; type <= 1; type++){
        for (int last = 1; last <= k[type]; last++){
            (ans += dp[n + m][m][type][last]) %= mod;
        }
    }
    cout << ans;
    return 0;
}
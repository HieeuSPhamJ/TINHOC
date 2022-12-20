#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int dp[110][110][10010];
int a[110];

bool cmp(int x, int y){
    return x > y;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);

    // dp[1][0][0] = 1;
    // dp[1][1][a[1]] = 1;

    dp[0][0][0] = 1;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 0; k < 10010; k++){
                int now = dp[i][j][k];
                // cout << "With: " << i << " " << j << " " << k << endl;
                // cout << now << endl;
                if (now){
                    // create and finish a team only with i
                    (dp[i + 1][j][k] += now) %= mod;
                    // cout << i + 1 << " " << j << " " << k << " " << dp[i + 1][j][k] << endl;
                    // create a new team
                    if (k + a[i + 1] < 10010){
                        (dp[i + 1][j + 1][k + a[i + 1]] += now) %= mod;
                        // cout << i + 1 << " " << j + 1 << " " << k + a[i + 1] << " " << dp[i + 1][j + 1][k + a[i + 1]] << endl;
                    }
                    if (j >= 1){
                        // finish a team
                        (dp[i + 1][j - 1][k - a[i + 1]] += j * now) %= mod;
                        // cout << i + 1 << " " << j - 1 << " " << k - a[i + 1] << " " << dp[i + 1][j - 1][k - a[i + 1]] << endl;
                        // add i to unfinish
                        (dp[i + 1][j][k] += j * now) %= mod;
                        // cout << i + 1 << " " << j << " " << k << " " << dp[i + 1][j][k] << endl;
                    }
                }
            }
        }
    }

    // cout << dp[2][0][0] << endl;

    int ans = 0;
    for (int i = 0; i <= m; i++){
        ans += dp[n][0][i];
        ans %= mod;
    }

    cout << ans;
    
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3010;

int a[maxN];

int dp[maxN][maxN];
int premin[maxN][maxN];

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
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = 1e18;
            premin[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int d = j - a[i];
            if (d >= 0){
                // cout << "Index: " << i << ' ' << j << " " << d << endl;
                if (d == 0){
                    // cout << "base" << endl;
                    dp[i][j] = 1;
                    if (i == 1){
                        dp[i][j] = 0;
                    }
                }
                else{
                    dp[i][j] = dp[i - 1][d];
                    if (i - 2 >= 1){
                        dp[i][j] = min(dp[i][j], premin[i - 2][d] + 1);
                    }
                    
                    // cout << i - 2 << endl;
                }
            }
            premin[i][j] = min(premin[i - 1][j], dp[i][j]);
        }
    }

    // for (int j = 1; j <= m; j++){
    //     for (int i = 1; i <= n; i++){
    //         int t = premin[i][j];
    //         if (t != 1e18){
    //             cout << t << " ";
    //         }
    //         else{
    //             cout << "- ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << "=======" << endl;

    // for (int j = 1; j <= m; j++){
    //     for (int i = 1; i <= n; i++){
    //         int t = dp[i][j];
    //         if (t != 1e18){
    //             cout << t << " ";
    //         }
    //         else{
    //             cout << "- ";
    //         }
    //     }
    //     cout << endl;
    // }

    for (int v = 1; v <= m; v++){
        int ans = min(dp[n][v], dp[1][v] + 1);
        for (int i = 2; i < n; i++){
            ans = min(ans, dp[i][v] + 1);
        }
        if (ans >= 1e18){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}
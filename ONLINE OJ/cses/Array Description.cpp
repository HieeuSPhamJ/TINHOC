#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN][110];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if (a[1] == 0){
        for (int i = 1; i <= m; i++){
            dp[1][i]++;
        }
    }
    else{
        dp[1][a[1]]++;
    }
    
    // dp[0]

    for (int i = 2; i <= n; i++){
        if (a[i] != 0){
            // cout << i << ":" << a[i] << endl;;
            for (int j = -1; j <= 1; j++){
                if (a[i] + j >= 1 and a[i] + j <= m){
                    // cout << a[i] + j << " ";
                    (dp[i][a[i]] += dp[i - 1][a[i] + j]) %= mod;
                }
            }
            // cout << endl;
            continue;
        }
        // cout 
        for (int j = 1; j <= m; j++){
            for (int jj = -1; jj <= 1; jj++){
                if (j + jj >= 1 and j + jj <= m){
                    (dp[i][j] += dp[i - 1][j + jj]) %= mod;
                }
            }
        }
    }
    int ans = 0;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    if (a[n] == 0){
        for (int i = 1; i <= m; i++){
            (ans += dp[n][i]) %= mod;
        }
    }
    else{
        ans = dp[n][a[n]];
    }
    cout << ans;

    return 0;
}
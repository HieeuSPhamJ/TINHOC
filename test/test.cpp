#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n, k, ans, dp[1000007][2];

main()
{
    cin >> n >> k;
    // cout << n << k;
    dp[1][1] = dp[1][0] = dp[0][0] = 1;
    for (int i = 2; i < k; i++)
    {
        dp[i][1] = dp[i][0];
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
    // }
    for (int i = k; i <= n; i++)
    {
        dp[i][1] = (dp[i - 1][1] - dp[i - k][0] + mod + dp[i - 1][0]) % mod;
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod;
    return 0;
}
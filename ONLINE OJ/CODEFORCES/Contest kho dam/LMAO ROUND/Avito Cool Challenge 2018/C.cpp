#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int mod = 998244353;

int dp[2010][2010];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    dp[1][0] = m;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            (dp[i + 1][j] += dp[i][j]) %= mod;
            (dp[i + 1][j + 1] = dp[i][j] * (m - 1)) %= mod;
        }

    }
    cout << dp[n][k];
    return 0;
}
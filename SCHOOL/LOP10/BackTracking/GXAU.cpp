#include<bits/stdc++.h>
using namespace std;

int dp[4][1000];

int main(){
    freopen("GXAU.INP", "r", stdin);
    freopen("GXAU.OUT", "w", stdout);

    int n;
    cin >> n;
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for (int i = 2; i <= n; i++){
        dp[1][i] +=  dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1];
        dp[2][i] += dp[1][i - 1] + dp[2][i - 1];
        dp[3][i] += dp[1][i - 1] + dp[3][i - 1];
    }
    cout << dp[1][n] + dp[2][n] + dp[3][n];

    return 0;
}
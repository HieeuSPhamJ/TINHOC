#include<bits/stdc++.h>
using namespace std;

long long a[100010];
long long dp[100010];

long long calMin(int i, int k){
    long long ans = 1e18;
    for (int e = 1; e <= k and i - e >= 0; e++){
        ans = min(ans, dp[i - e] + abs(a[i] - a[i - e]));
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = 0;
    dp[0] = dp[1] = 0;
    dp[2] = calMin(2, k);
    for (int i = 3; i <= n; i++){
        dp[i] = calMin(i, k);
    }
    cout << dp[n];
    // cout << dp[2];
    return 0;
}
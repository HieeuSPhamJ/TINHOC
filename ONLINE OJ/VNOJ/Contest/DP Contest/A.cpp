#include<bits/stdc++.h>
using namespace std;

int a[100010];
int dp[100010];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = 0;
    dp[0] = dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout << dp[n];
    return 0;
}
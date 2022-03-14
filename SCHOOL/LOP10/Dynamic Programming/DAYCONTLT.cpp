#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN];
int dp[maxN];

int main(){
    freopen("DAYCONTLT.INP", "r", stdin);
    freopen("DAYCONTLT.OUT", "w", stdout);
    
    int n;
    cin >> n;   
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++){
        dp[i] = 1;
        if (a[i - 1] <= a[i]){
            dp[i] += dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
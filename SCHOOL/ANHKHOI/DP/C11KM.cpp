#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;


int a[1010];
int dp[1010][1010];


int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n + 1; i++){
        for (int e = 0; e <= n + 1; e++){
            dp[i][e] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int e = 0; e <= n; e++){
            if (a[i] > 100 and e >= 1){
                dp[i][e] = min(dp[i - 1][e - 1] + a[i], dp[i - 1][e + 1]);
            }
            else{
                dp[i][e] = min(dp[i - 1][e] + a[i], dp[i - 1][e + 1]);
            }
            // cout << dp[i][e] << ' ';
        }
        // cout << endl;
    }
    int ans = inf;
    for (int i = 0; i <= n; i++){
        ans = min(ans,dp[n][i]);
    }
    cout << ans;
    return 0;
}
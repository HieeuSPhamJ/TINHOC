#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;
int a[maxN];
int dp[maxN][3][3];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        
        if (a[1] == 1){
            // dp[1][1][1] = 1;
            for (int i = 0; i <= 1; i++){
                for (int j = 0; j <= 2; j++){
                    for (int k = 0; k <= 2; k++){
                        dp[i][j][k] = 1;
                    }
                }
            }
        }
        else{
            // dp[1][1][1] = 0;
            for (int i = 0; i <= 1; i++){
                for (int j = 0; j <= 2; j++){
                    for (int k = 0; k <= 2; k++){
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
        for (int i = 2; i <= n; i++){
            if (a[i] == 0){
                dp[i][1][1] = min(dp[i - 1][1][2], dp[i - 1][2][2]);
                dp[i][1][2] = min(dp[i - 1][1][1], dp[i - 1][2][1]);
                dp[i][2][1] = dp[i - 1][1][1];
                dp[i][2][2] = dp[i - 1][1][2];
            }
            else{
                dp[i][1][1] = min(dp[i - 1][1][2], dp[i - 1][2][2]) + 1;
                dp[i][1][2] = min(dp[i - 1][1][1], dp[i - 1][2][1]);
                dp[i][2][1] = dp[i - 1][1][1] + 1;
                dp[i][2][2] = dp[i - 1][1][2];
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= 2; i++){   
        for (int j = 1; j <= 2; j++){
            ans = min(ans, dp[n][i][j]);
        }
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;
int a[maxN];
int dp[maxN][5];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k, z;
        cin >> n >> k >> z;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            for (int j = 0; j <= 5; j++){
                dp[i][j] = 0;
            }
        }
        int ans = 0;
        dp[0][0] = a[0];
        for (int i = 1; i <= k; i++){
            for (int j = 0; j < min(i, z); j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i - j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i - j]);

                ans = max(ans, dp[i][j]);
            }
        }
        
        for (int i = 0; i <= k; i++){
            for (int j = 0; j <= z; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}


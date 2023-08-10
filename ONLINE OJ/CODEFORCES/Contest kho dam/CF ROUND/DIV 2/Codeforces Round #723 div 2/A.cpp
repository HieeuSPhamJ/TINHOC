#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2010;

int a[maxN];
int dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= 1 and a[i] + dp[i - 1][j - 1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++){
        if (dp[n][i] >= 0){
            ans = max(ans, i);
        }
    }
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;
int a[maxN];
int dp[maxN][4];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++){
        dp[i][1] = -1e18;
        dp[i][2] = -1e18;
        dp[i][3] = -1e18;
    }
    for (int i = 1; i <= n; i++){
        dp[i][1] = max(dp[i - 1][1], a[i] * x);
        dp[i][2] = max({dp[i - 1][2], dp[i - 1][1] + a[i] * y, dp[i][1] + a[i] * y});
        dp[i][3] = max({dp[i - 1][3], dp[i - 1][2] + a[i] * z, dp[i][2] + a[i] * z});
    }
    cout << dp[n][3];
    return 0;
}
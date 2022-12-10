#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int a[maxN];
int dp[maxN][4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][0] = max(0ll, a[i]);
        dp[i][1] = max(0ll, dp[i][1] * x);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i][0],dp[i - 1][0] + a[i]);
        dp[i][1] = max({dp[i][1], dp[i - 1][0] + a[i] * x, dp[i - 1][1] + a[i] * x});
        dp[i][2] = max({dp[i][2], dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]});
        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
    }

    cout << ans;

    return 0;
}
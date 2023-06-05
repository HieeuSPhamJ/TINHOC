#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int dp[maxN][3];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[2][0] = a[1] - 1;
    dp[2][1] = max(a[2] - 1, abs(a[2] - a[1]));
    for (int i = 2; i <= n; i++){
        // cout << dp[i][0] << " " << dp[i][1] << endl;
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + a[i] - 1);
        dp[i + 1][1] = max(dp[i][1] + abs(a[i] - a[i + 1]), dp[i][0] + a[i + 1] - 1);
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
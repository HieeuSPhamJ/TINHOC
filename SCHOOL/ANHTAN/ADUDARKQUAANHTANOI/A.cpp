#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e3 + 10;
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
    int ans = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i]);
        ans = max(dp[i][0], dp[i][1]);
    }
    cout << ans;
    return 0;
}
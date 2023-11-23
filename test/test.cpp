#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("hanhan.inp", "r")) {
        freopen("hanhan.inp", "r", stdin);
        freopen("hanhan.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h[101];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    int dp[1001], pref[1001];
    for (int i = 0; i <= h[1]; i++) pref[i] = i + 1;
    for (int i = h[1] + 1; i <= 1000; i++) pref[i] = h[1] + 1;
    for (int i = 2; i <= n; i++) {
        memset(dp, 0, sizeof dp);
        for (int j = 0; j <= h[i]; j++) {
            dp[j] = pref[h[i] - j];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
        for (int j = 0; j <= 1000; j++) {
            pref[j] = dp[j];
            if (j) pref[j] += pref[j - 1];
            if (pref[j] >= MOD) pref[j] -= MOD;
        }
    }
    cout << pref[0];
    return 0;
}
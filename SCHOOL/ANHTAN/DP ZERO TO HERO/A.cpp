#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dp[n + 2];
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}
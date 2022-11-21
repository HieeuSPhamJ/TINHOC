#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];
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
    for (int i = 1; i < n; i++){
        cin >> b[i];
    }
    dp[n][0] = a[n];
    dp[n][1] = a[n];
    for (int i = n - 1; i >= 1; i--){
        dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]) + a[i];
        dp[i][1] = min(dp[i + 2][0], dp[i + 2][1]) + b[i];
        // cout << i << ": " << dp[i][0] << "-" << dp[i][1] << endl;
        // cout << a[i] << " " << b[i] << endl;
    }
    
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
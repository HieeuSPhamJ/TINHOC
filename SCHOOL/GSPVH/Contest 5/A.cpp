#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2210;

ii a[maxN];
int dp[maxN][5610];

signed main(){
    freopen("knapsack.INP", "r", stdin);
    freopen("knapsack.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - a[i].fi >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].fi] + a[i].se);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
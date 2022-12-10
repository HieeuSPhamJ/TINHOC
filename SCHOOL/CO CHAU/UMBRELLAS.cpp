#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5010;
const int maxM = 1e6 + 10;
const int inf = 1e18;

int a[maxN];
int cost[maxM];
int dp[maxN];

signed main(){
    freopen("UMBRELLAS.inp", "r", stdin);
    freopen("UMBRELLAS.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = inf;
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= m; i++){
        cin >> cost[i];
    }

    
    for (int i = m, minval = cost[m]; i >= 1; i--){
        minval = min(minval, cost[i]);
        cost[i] = minval;
    }

    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        for (int j = i, minval = dp[j]; j >= 1; j--){
            minval = min(minval, dp[j - 1]);
            // cout << minval << " " << (i - j + 1) << endl;
            dp[i] = min(dp[i], minval + cost[(a[i] - a[j] + 1)]);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[n];

    return 0;
}

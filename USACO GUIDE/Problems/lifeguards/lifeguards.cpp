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

const int maxN = 1e5 + 10;

ii a[maxN];
int dp[maxN][110];

bool cmp(ii x, ii y){
    return x.se < y.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("lifeguards.in", "r")) {
        freopen("lifeguards.in", "r", stdin);
        freopen("lifeguards.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        a[i].se--;
    }
    sort(a + 1, a + 1 + n, cmp);
    // for (int i = 1; i <= n; i++){
    //     cout << a[i].fi << " " << a[i].se << endl;
    // }
    // cout << "====" << endl;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        ii cur = a[i];
        for (int j = 0; j <= k; j++){
            // cout << "with: " << i << ' ' << j << ": " << endl;
            for (int g = 0; i - g - 1 >= 0 and j - g >= 0; g++){
                ii la = a[i - g - 1];
                int cost = cur.se - cur.fi + 1;
                if (la.se >= cur.fi){
                    cost = cur.se - la.se;
                }
                dp[i][j] = max(dp[i][j], dp[i - g - 1][j - g] + cost);
                // cout << " " << i - g - 1 << " " << j - g << ": " << dp[i - g - 1][j - g] + cost << endl;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (k - (n - i) >= 0){
            // cout << i << " " << k - (n - i) << endl;
            res = max(res, dp[i][k - (n - i)]);
        }
    }
    cout << res << endl;
    return 0;
}
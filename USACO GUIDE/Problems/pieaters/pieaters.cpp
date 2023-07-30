#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 310;

pair<ii,int> a[1000000];
int dp[maxN][maxN];
int mx[maxN][maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a[i].se >> a[i].fi.fi >> a[i].fi.se;
    }

    for (int i = 1; i <= m; i++){
        for (int j = a[i].fi.fi; j <= a[i].fi.se; j++){
            mx[j][a[i].fi.fi][a[i].fi.se] = a[i].se;
        }
    }
    for (int r = 1; r <= n; r++){
        for (int l = r; l >= 1; l--){
            for (int i = l; i <= r; i++){
                mx[i][l][r] = max({mx[i][l][r], mx[i][l + 1][r], mx[i][l][r - 1]});
                // cout << i << " " << l << " " << r << ": " << mx[i][l][r] << endl;
            }
        }
    }
    int res = 0;
    for (int r = 1; r <= n; r++){
        for (int l = r; l >= 1; l--){
            for (int i = l; i <= r; i++){
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
                dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + mx[i][l][r]);
            }
            res = max(res,dp[l][r]);
        }
    }

    cout << res << endl;
    return 0;
}
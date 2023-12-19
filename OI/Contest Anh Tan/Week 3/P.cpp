#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2000 + 10;
const int inf = 1e18;

int n;
int base;
ii a[maxN];
int dp[maxN][2 * maxN];

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int co(int x){
    if (x < -n){
        x = -n;
    }
    if (x > n){
        x = n;
    }
    return x + base;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    base = n + 1;
    memset(dp, 0x3f, sizeof(dp));
    dp[1][co(-1)] = 0;
    dp[1][co(a[1].fi)] = a[1].se;

    for (int i = 1; i < n; i++){
        for (int j = - n; j <= n; j++){
            int cur = dp[i][co(j)];
            if (cur >= inf){
                continue;
            }
            // cout << i << " " << j << ": " << cur << endl;
            minimize(dp[i + 1][co(j - 1)], cur);
            // cout << " =>" << i + 1 << " " << j - 1 << ": " << dp[i + 1][co(j - 1)] << endl;
            minimize(dp[i + 1][co(j + a[i + 1].fi)], cur + a[i + 1].se);
            // cout << " =>" << i + 1 << " " << j + a[i + 1].fi << ": " << dp[i + 1][co(j + a[i + 1].fi)] << endl;
        }
    }

    int res = inf;
    for (int i = 0; i <= n; i++){
        res = min(res, dp[n][co(i)]);
        // cout << i << " " << dp[n][co(i)] << endl;
    }
    cout << res << endl;
    return 0;
}
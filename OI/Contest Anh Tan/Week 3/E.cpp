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

const int inf = 1e18;

int dp[180][180][180];
int a[180];
int co[180][180];
ii pre[180][180];

void insert(ii &s, int x){
    if (s.fi == inf){
        s.fi = x;
        return;
    }
    if (s.se == inf){
        s.se = x;
        if (s.fi > s.se){
            swap(s.fi,s.se);
        }
        return;
    }
    if (x < s.fi){
        s.se = s.fi;
        s.fi = x;
        return;
    }
    if (x < s.se){
        // cout << "*" << endl;
        s.se = x;
        return;
    }
}

void erase(ii &s, int x){
    if (s.fi == x){
        s.fi = s.se;
        s.se = inf;
        return;
    }
    if (s.se == x){
        s.se = inf;
        return;
    }
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> co[i][j];
            if (a[i] == j){
                co[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++){
    for (int j = 0; j <= k; j++){
    for (int c = 0; c <= m; c++){
        dp[i][j][c] = inf;
    }
    }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            pre[i][j] = {inf, inf};
        }
    }
    pre[0][0] = {0,0};
    memset(dp[0][0], 0, sizeof(dp[0][0]));
    for (int i = 1; i <= n; i++){
    for (int j = 1; j <= k; j++){
    int st = 1;
    int en = m;
    if (a[i] != 0){
        st = en = a[i];
    }
    for (int c = st; c <= en; c++){
        // cout << "With: " << i << " " << j << " " << c << ": " << endl;
        if (dp[i - 1][j][c] != inf){
            dp[i][j][c] = dp[i - 1][j][c] + co[i][c];
        }
        ii s = pre[i - 1][j - 1];
        erase(s, dp[i - 1][j - 1][c]);
        if (s.fi != inf){
            dp[i][j][c] = min(dp[i][j][c], s.fi + co[i][c]);
        }
        if (dp[i][j][c] == inf){
            continue;
        }
        insert(pre[i][j], dp[i][j][c]);
        // cout << dp[i][j][c] << endl;
        // cout << pre[i][j].fi << " " << pre[i][j].se << endl;
    }
    }
    }
    int res = 1e18;
    for (int i = 1; i <= m; i++){
        res = min(res, dp[n][k][i]);
    }
    if (res == inf){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}
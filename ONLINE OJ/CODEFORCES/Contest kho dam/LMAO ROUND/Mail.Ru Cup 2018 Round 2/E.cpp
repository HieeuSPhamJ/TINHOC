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

const int maxN = 2e3 + 10;


int n, s, m, k;
int a[maxN];
ii b[maxN];
int le[maxN];
int pre[maxN];
int dp[maxN][maxN];

bool check(int mid){
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + (a[i] <= mid);
        // cerr << le[i] << " ";
    }
    // cerr << endl;

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if (le[i] <= i){
                dp[i][j] = max(dp[i][j], dp[le[i] - 1][j - 1] + pre[i] - pre[le[i] - 1]);
            }
            // cout << i << " " << j << endl;
            // cout << dp[i][j] << endl;
        }
    }

    return dp[n][m] >= k;
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
    cin >> n >> s >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= s; i++){
        cin >> b[i].fi >> b[i].se;
    }
    memset(le, 0x3f, sizeof(le));
    for (int i = 1; i <= s; i++){
        for (int j = b[i].fi; j <= b[i].se; j++){
            le[j] = min(le[j], b[i].fi);
        }
    }

    int res = -1;
    int l = 1;
    int r = 1e18;
    while(l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid - 1;
            res = mid;
        }
        else{
            l = mid + 1;
        }
    }
    // cout << check(1) << endl;
    // cout << check(2) << endl;
    // cout << check(3) << endl;
    cout << res << endl;
    return 0;
}

/*
dp[i]
*/
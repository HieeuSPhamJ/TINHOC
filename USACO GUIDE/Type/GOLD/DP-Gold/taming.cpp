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

const int maxN = 110;

int a[maxN];
int dp[maxN][maxN][maxN];

int minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("taming.in", "r")) {
        freopen("taming.in", "r", stdin);
        freopen("taming.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int t = 1; t <= n; t++){
        memset(dp, 0x3f, sizeof(dp));
        dp[1][1][0] = (a[1] != 0);
        for (int i = 1; i < n; i++){
            for (int j = 1; j <= t; j++){
                for (int k = 0; k <= i; k++){
                    int cur = dp[i][j][k];
                    // cout << i << ' ' << j << ' ' << k << " " << cur << endl;
                    minimize(dp[i + 1][j][k + 1], cur + (a[i + 1] != k + 1));
                    minimize(dp[i + 1][j + 1][0], cur + (a[i + 1] != 0));
                }
            }
        }
        int res = 1e18;
        for (int i = 0; i <= n; i++){
            res = min(res, dp[n][t][i]);
        }
        cout << res << endl;
    }
    return 0;
}
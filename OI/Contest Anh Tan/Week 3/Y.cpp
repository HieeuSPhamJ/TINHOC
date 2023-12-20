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

int a[110];
int dp[110][20010];

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
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
    int n;
    cin >> n;
    int base = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        base += a[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][base] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = -base; j <= base; j++){
            int cur = dp[i - 1][j + base];
            if (cur == -1){
                continue;
            }
            // cout << i - 1 << " " << j << ": " << cur << endl; 
            maximize(dp[i][j + base], cur);
            maximize(dp[i][j - a[i] + base], cur);
            maximize(dp[i][j + a[i] + base], cur + a[i]);
        }
    }
    cout << max(0ll, dp[n][base]) << endl;
    return 0;
}
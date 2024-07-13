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


const int maxN = 3e5 + 10;

int a[maxN];

int dp[maxN][20];

bool minimize(int &a, int b){
    if (a > b){
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
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= k; j++){
                dp[i][j] = 1e18;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= min(i,k); j++){
                int cur = dp[i][j];
                // cout << "with: " << i << " " << j << ": " << cur << endl;
                for (int dt = 1, mi = 1e18; i + dt <= n and dt + j - 1 <= k; dt++){
                    mi = min(mi, a[i + dt]);
                    // cout << "#" << i + dt << " " << dt + j - 1 << endl;
                    // cout << dp[i + dt][dt + j - 1] << " " << mi << endl;
                    if (minimize(dp[i + dt][dt + j - 1], cur + mi * dt)){
                        // cout << "=>" << dp[i + dt][dt + j - 1] << endl;
                    }
                }
            }
        }
        int res = 1e18;
        for (int i = 0; i <= k; i++){
            res = min(res, dp[n][i]);
            // cout << dp[n][i] << endl;
        }
        cout << res << endl;

    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int dp[maxN][22];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k, x;
        cin >> n >> k >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= k; j++){
                dp[i][j] = -1e18;
            }
        }
        dp[1][0] = a[1] - x;
        dp[1][1] = a[1] + x;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= min(k,i); j++){
                int now = dp[i][j];
                if (now != 1e18){
                    dp[i + 1][j] = max({a[i] - x,dp[i + 1][j], now + a[i] - x});
                    dp[i + 1][j + 1] = max({a[i] - x,dp[i + 1][j + 1], now + a[i] + x});
                }
            }
        }

        for (int j = 0; j <= k; j++){
            cout << j << ": ";
            for (int i = 1; i <= n; i++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
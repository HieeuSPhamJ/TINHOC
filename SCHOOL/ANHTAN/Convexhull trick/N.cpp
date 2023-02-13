#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;
const int mod = 1e9 + 7;

int a[maxN][maxN];
int dp[maxN][maxN];
int invdp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i <= n + 1; i++){
            for (int j = 0; j <= m + 1; j++){
                dp[i][j] = 0;
                invdp[i][j] = 0;
            }
        }
        dp[1][1] = 1;
        invdp[n][m] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] == 1){
                    (dp[i][j] = max(dp[i][j],dp[i - 1][j] + dp[i][j - 1])) %= mod;
                }
            }
        }
        for (int i = n; i >= 1; i--){
            for (int j = m; j >= 1; j--){
                if (a[i][j] == 1){
                    (invdp[i][j] = max(invdp[i][j],invdp[i + 1][j] + invdp[i][j + 1])) %= mod;
                }
            }
        }
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << invdp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ok = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] and make_pair(i,j) != make_pair(n,m) and make_pair(i,j) != make_pair(1ll,1ll)){
                    if ((dp[i][j] * invdp[i][j]) % mod == dp[n][m]){
                        ok = 1;
                        // cout << i << " " << j << endl;
                    }
                }
            }
        }
        if (ok or dp[n][m] == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }

    return 0;
}
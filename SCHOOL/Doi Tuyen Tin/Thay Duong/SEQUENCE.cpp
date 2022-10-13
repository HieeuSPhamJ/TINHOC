#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1010;
const int mod = 1e9 + 7;
int a[maxN];
int dp[maxN][maxN][3];
int sum[maxN][maxN][3];

signed main(){
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
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
                dp[i][j][0] = dp[i][j][1] = 0;
                sum[i][j][0] = sum[i][j][1] = 0;
            }
            sum[i][0][0] = 1;
        }
        dp[0][0][0] = 1;
        sum[0][0][0] = 1;
        for (int i = 1; i <= n; i++){
            // cout << "INDEX" << endl;
            for (int j = 1; j <= min(i,k); j++){
                // cout << i << " " << j << endl; 
                if (a[i] % 2 == 0){
                    // cout << "CHAN" << endl;
                    // cout << i - 1 << " " << j - 1 << endl;
                    (dp[i][j][0] += sum[i - 1][j - 1][0]) %= mod;
                    (dp[i][j][1] += sum[i - 1][j - 1][1]) %= mod; 
                }
                else{
                    // cout << "LE" << endl;
                    // cout << i - 1 << " " << j - 1 << endl;
                    (dp[i][j][0] += sum[i - 1][j - 1][1]) %= mod;
                    (dp[i][j][1] += sum[i - 1][j - 1][0]) %= mod; 
                }
                (sum[i][j][0] = sum[i - 1][j][0] + dp[i][j][0]) %= mod;
                (sum[i][j][1] = sum[i - 1][j][1] + dp[i][j][1]) %= mod;
                // cout << dp[i][j][0] << " " << dp[i][j][1] << " " << sum[i][j][0] << " " << sum[i][j][1] << endl;
            }
        }
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= k; j++){
        //         cout << dp[i][j][0] << "," << dp[i][j][1] << "  ";
        //     }
        //     cout << endl;
        // }
        cout << sum[n][k][1] << endl;
    }
    return 0;
}
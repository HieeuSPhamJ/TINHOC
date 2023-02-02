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
const int mod = 1e9 + 9;

int a[maxN];
int b[maxN];

int dp[maxN][maxN][12];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j][0] = 1;
        }
    }

    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= K; k++){
                (dp[i][j][k] = (dp[i][j - 1][k] + dp[i - 1][j][k]) % mod - dp[i - 1][j - 1][k] + mod) %= mod;
                if (a[i] > b[j]){
                    // cout << "ok" << endl;
                    (dp[i][j][k] += dp[i - 1][j - 1][k - 1]) %= mod;
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    cout << dp[n][m][K];

    return 0;
}
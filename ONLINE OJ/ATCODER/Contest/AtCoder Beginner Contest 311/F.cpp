#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e3 + 10;
const int mod = 998244353;

int a[maxN];
int dp[maxN][maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == '#'){
                a[j] = max(i,a[j]);
            }
        }
    }

    dp[0][0] = 1;

    // for (int i = 1; i <= m; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= m; i++){
        pre[0] = dp[i - 1][0];
        for (int j = 1; j <= n + 1; j++){
            (pre[j] = pre[j - 1] + dp[i - 1][j]) %= mod;
        }
        for (int j = a[i]; j <= n; j++){
            dp[i][j] = pre[j + 1];
        }
    }

    // for (int i = n; i >= 1; i--){
    //     for (int j = 0; j <= m; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    int res = 0;

    for (int i = 0; i <= n; i++){
        (res += dp[m][i]) %= mod;
    }

    cout << res << endl;

    return 0;
}
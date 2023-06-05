#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[maxN][1 << 4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    dp[1][1] = 1;
    dp[1][1 << 1] = 1;
    dp[1][1 << 2] = 1;
    dp[1][1 << 3] = 1;
    for (int i = 1; i <= m; i++){
        for (int mask = 0; mask < (1 << 4); mask++){
            int now = dp[i][mask];
            for (int j = 0; j < 4; j++){
                (dp[i + 1][mask | (1 << j)] += now) %= mod;
            }
        }
    }

    int res = 0;
    for(int mask = 0; mask < (1 << 4); mask++){
        if(__builtin_popcount(mask) >= k){
            // cout << bitset<4>(mask) << " " << dp[m][mask] << endl;
            (res += dp[m][mask]) %= mod;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++){
        (ans *= res) %= mod;
    }

    cout << ans << endl;

    return 0;
}
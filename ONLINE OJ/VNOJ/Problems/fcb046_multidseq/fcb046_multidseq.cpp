#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int dp[51][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        dp[1][i]++;
    }

    for (int i = 1; i < k; i++){
        for (int j = 1; j <= n; j++){
            if (dp[i][j] == 0){
                continue;
            }
            for (int x = 1; x * j <= n; x++){
                dp[i + 1][x * j] += dp[i][j];
                // cout << j << " " << x * j << endl;
            }
        }
    }

    int ans = 0;
    
    for (int i = 1; i <= n; i++){
        ans += dp[k][i];
        ans %= mod;
    }

    cout << ans;

    return 0;
}
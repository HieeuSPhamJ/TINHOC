#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1000;

int a[maxN];
int dp[maxN][maxN];
int prefix[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = 1e18;       
        }
    }
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        dp[i][1] = prefix[i];
        for (int k = 2; k <= i; k++){
            // cout << "With: " << i << " " << k << endl;
            for (int j = 1; j <= i; j++){
                if (dp[j - 1][k - 1] <= prefix[i] - prefix[j - 1]){
                    dp[i][k] = min(dp[i][k], prefix[i] - prefix[j - 1]);
                    ans = max(ans, k);
                    // cout << j << " " << dp[i][k] << endl;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
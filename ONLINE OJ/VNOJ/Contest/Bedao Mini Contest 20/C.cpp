#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[(1 << 10)];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        memset(dp,0,sizeof(dp));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            int t = x;
            int mask = 0;
            while(x){
                if (mask & (1 << x % 10)){
                    goto bru;
                }
                mask = mask | (1 << x % 10);
                x /= 10;
            }
            for (int tmask = 0; tmask < (1 << 10); tmask++){
                if (mask & tmask or dp[tmask] == 0){
                    continue;
                }
                dp[mask | tmask] = max(dp[mask | tmask],dp[tmask] + t);
            }
            dp[mask] = max(dp[mask],t);
            bru:;
        }
        int res = 0;
        for (int i = 0; i < (1 << 10); i++){
            res = max(res,dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}
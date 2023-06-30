#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[2010][2];
ii a[2020];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi >> a[i].se;
            dp[i][1] = dp[i][0] = 1e18;
            
        }
        sort(a + 1, a + 1 + n);
        int res = 0;
        dp[0][1] = 0;
        dp[0][0] = 1e18;
        for (int i = 0; i < n; i++){
            for (int t = 0; t <= 1; t++){
                int curr = dp[i][t];
                for (int j = i + 1; j <= n; j++){
                    if (t == 0){
                        dp[j][1] = min(dp[i][1])
                    }
                }
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 200;

int a[maxN];
int dp[maxN * 10000];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ii nu;
        int n;
        cin >> nu.fi >> nu.se >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 0; i <= sum; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int s = sum - a[i]; s >= 0; s--){
                if (dp[s]){
                    dp[s + a[i]] = 1;
                }
            }
        }

        int res = 1e18;

        for (int s = 0; s <= sum; s++){
            if (dp[s]){
                ii te = {s, sum - s};
                int t = max((nu.fi + te.fi - 1) / nu.fi, (nu.se + te.se - 1) / nu.se);
                res = min(res, t);
            }
        }
        cout << res << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[21][(1 << 20)];

int a[22];
int sum[(1 << 20)];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if ((mask & (1 << i))){
                sum[mask] += a[i];
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            if (sum[mask] <= x){
                dp[i][mask] = 1;
            }
            for (int sub = mask; sub > 0; sub = mask & (sub - 1)){
                int now = (mask xor sub);
                if (sum[now] <= x and dp[i - 1][sub]){
                    dp[i][mask] = 1;
                    break;
                }
            }
            // cout << i << " " << bitset<4>(mask) << ": " << dp[i][mask] << endl;
        }
        if (dp[i][(1 << n) - 1]){
            cout << i;
            return 0;
        }
    }
    return 0;
}
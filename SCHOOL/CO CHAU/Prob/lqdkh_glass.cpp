#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a[25][25];
vector <int> ls[25];
vector <int> has[(1 << 20)];
vector <int> nothas[(1 << 20)];
int dp[(1 << 20)];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("glass.inp", "r")) {
        freopen("glass.inp", "r", stdin);
        freopen("glass.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            // a[i][j] = 1;
        }
    }

    if (n == k){
        cout << 0 << endl;
        return 0;
    }

    for (int mask = 0; mask < (1 << n); mask++){
        ls[__builtin_popcount(mask)].push_back(mask);
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                has[mask].push_back(i);
            }
            else{
                nothas[mask].push_back(i);
            }
        }
    }
    int ans = 1e18;
    for (int cnt = n - 1; cnt >= k; cnt--){
        for (auto mask: ls[cnt]){
            int res = 1e18;
            // cout << bitset <5> (mask) << ": " << endl;
            for (auto i: nothas[mask]){
                for (auto j: has[mask]){
                    res = min(res, dp[mask | (1 << i)] + a[i][j]);
                    // cout << i << " " << j << " " << dp[mask | (1 << i)] + a[i][j] << endl;
                }
            }
            dp[mask] = res;
            // cout << res << endl;
            if (cnt == k){
                ans = min(ans,res);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
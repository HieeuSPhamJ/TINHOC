#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int dp[310][310];
int a[310];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("daruma.inp", "r")) {
        freopen("daruma.inp", "r", stdin);
        freopen("daruma.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        int n;
        cin >> n;
        if (n == 0){
            return 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int r = 2; r <= n; r++){
            for (int l = r - 1; l >= 1; l--){
                dp[l][r] = 0;
                if (r - l == 1 and abs(a[l] - a[r]) <= 1){
                    dp[l][r] = 2;
                    continue;
                }
                if (abs(a[l] - a[r]) <= 1 and dp[l + 1][r - 1] == r - l - 1){
                    dp[l][r] = r - l + 1;
                    continue;
                }
                for (int i = l; i < r; i++){
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
                }
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
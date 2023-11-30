#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e4 + 10;
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN];
int ndp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("jedan.inp", "r")) {
        freopen("jedan.inp", "r", stdin);
        freopen("jedan.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 1;
    if ((a[1] != -1 and a[1] != 0) or (a[n] != -1 and a[n] != 0)){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        if (a[i] != -1){
            (ndp[a[i]] += dp[a[i]]) %= mod;
            (ndp[a[i]] += dp[a[i] + 1]) %= mod;
            if (a[i] != 0){
                (ndp[a[i]] += dp[a[i] - 1]) %= mod;
            }
        }
        else{
            for (int j = 0; j <= n; j++){
                if (dp[j] == 0){
                    continue;
                }
                if (j != 0){
                    (ndp[j - 1] += dp[j]) %= mod;
                }
                (ndp[j] += dp[j]) %= mod;
                (ndp[j + 1] += dp[j]) %= mod;
            }
        }
        // cout << "With: " << i << endl;
        for (int j = 0; j <= n; j++){
            (dp[j] = ndp[j]) %= mod;
            ndp[j] = 0;
            // cout << dp[j] << " ";
        }
        // cout << endl;
    }
    cout << dp[0] << endl;
    return 0;
}
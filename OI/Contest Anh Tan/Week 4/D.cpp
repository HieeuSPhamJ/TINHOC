#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

int dp[510][510];
int co[510][510];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    s = "!" + s;

    for (int r = 1; r <= n; r++){
        co[r][r] = 0;
        co[r - 1][r] = (s[r - 1] != s[r]);
        for (int l = r - 2; l >= 1; l--){
            co[l][r] = co[l + 1][r - 1] + (s[l] != s[r]);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = i; j <= n; j++){
    //         cout << i << " " << j << ": " << co[i][j] << endl;
    //     }
    // }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            // cout << i << " " << j << ": " << endl;
            for (int s = i; s >= 1; s--){
                if (dp[s - 1][j - 1] <= n){
                    // cout << s - 1 << " " << dp[s - 1][j - 1] << " " << co[s][i] << endl;
                    minimize(dp[i][j], dp[s - 1][j - 1] + co[s][i]);
                }
            }
            // cout << dp[i][j] << endl;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
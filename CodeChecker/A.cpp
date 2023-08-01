#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

 int n, m;
int dp[1010][10010];
int pre[40010];

int sum(int i, int j){
    // cout << i << " " << j << endl;
    return pre[j + 1] - pre[i];
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> m;
    dp[1][0] = 1;

    for (int i = 2; i <= n; i++){
        pre[1] = dp[i - 1][0];
        for (int j = 1; j <= m; j++){
            pre[j + 1] = pre[j] + dp[i - 1][j];
            pre[j + 1] %= mod;
            // cout << pre[j + 1] << " ";
        }
        // cout << endl;
        for (int j = 0; j <= m; j++){
            int k = i - 1;
            // cout << i << " " << j << ": " << endl;
            dp[i][j] = sum(max(0ll, j - k), j) + mod;
            dp[i][j] %= mod;
            // cout << dp[i][j] << endl;
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << dp[n][m] << endl;
    return 0;
}
/*
12
*/
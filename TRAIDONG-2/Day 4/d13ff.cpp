#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int dp[110][110];
int cur[110][110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        for (int j = i + 1; j < m; j++){
            dp[i][j] = 1e18; 
            cur[i][j] = a[m - i] + a[m - j];
        }
    }
    for (int i = m; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = j + 1; k < m; k++){
                // cout << i << " " << j << " " << k << ": " << cur[j][k] << endl;
                dp[j + 1][k + 1] = min(dp[j + 1][k + 1], cur[j][k]);
                // cout << " =>" << i + 1 << " " << j + 1 << " " << k + 1 << " " << dp[j + 1][k + 1] << endl;
                dp[0][j + 1] = min(dp[0][j + 1], cur[j][k] + a[i + 1]);
                // cout << " =>" << i + 1 << " " << 0 << " " << j + 1 << " " << dp[0][j + 1] << endl;
            }
        }
        for (int j = 0; j < m; j++){
            for (int k = j + 1; k < m; k++){
                cur[j][k] = dp[j][k];
                dp[j][k] = 1e18;
            }
        }
    }

    int res = 1e18;

    for (int j = 0; j < m; j++){
        for (int k = j + 1; k < m; k++){
            res = min(res, cur[j][k]);
        }
    }

    cout << res << endl;
    return 0;
}

/*
dp[i][j][k]: xet den i 2 thang chon gan nhat cach i la j va k
dp[i][j][k]
=> dp[i + 1][j + 1][k + 1]
dp[i + 1][j + 1][k + 1]
dp[i + 1][k + 1][0]


1 1 5 2 1

3 0 1: 6
 =>4 1 2 6
 =>4 0 1 11
3 0 2: 6
 =>4 1 3 0
 =>4 0 1 11
3 1 2: 2
 =>4 2 3 0
 =>4 0 2 7
4 0 1: 11
 =>5 1 2 11
 =>5 0 1 13
4 0 2: 7
 =>5 1 3 0
 =>5 0 1 9
4 1 2: 6
 =>5 2 3 0
 =>5 0 2 8

*/

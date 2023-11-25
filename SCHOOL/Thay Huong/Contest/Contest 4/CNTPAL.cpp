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

const int maxN = 5010;

int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("CNTPAL.inp", "r")) {
        freopen("CNTPAL.inp", "r", stdin);
        freopen("CNTPAL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int r = 1; r <= n; r++){
        for (int l = r; l >= 1; l--){
            dp[l][r] = (s[l] == s[r]);
            if (r - l <= 1){
                continue;
            }
            dp[l][r] *= dp[l + 1][r - 1];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // cout << dp[i][j] << " ";
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
        // cout << endl;
    }

    int test;
    cin >> test;
    while(test--){
        int x, y;
        cin >> x >> y;
        cout << dp[y][y] - dp[x - 1][y] - dp[y][x - 1] + dp[x - 1][x - 1] << endl;
    }
    return 0;
}
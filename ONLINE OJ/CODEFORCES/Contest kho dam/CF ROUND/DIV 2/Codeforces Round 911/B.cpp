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

int dp[4][110][110][110];

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
    int mav = 3;
    for (int i = 1; i <= mav; i++){
        dp[1][i][0][0] = 1;
        dp[2][0][i][0] = 1;
        dp[3][0][0][i] = 1;
    }
    for (int t = 1; t <= 3; t++){
    for (int i = 0; i <= mav; i++){
    for (int j = 0; j <= mav; j++){
    for (int k = 0; k <= mav; k++){
        if (i * j){
            dp[t][i][j][k] |= dp[t][i - 1][j - 1][k];
        }
        if (i * k){
            dp[t][i][j][k] |= dp[t][i - 1][j][k - 1];
        }
        if (k * j){
            dp[t][i][j][k] |= dp[t][i][j - 1][k - 1];
        }
        cout << t << " " << i << " " << j << " " << k << ": " << dp[t][i][j][k] << endl; 
    }
    }
    }
    }
    int test;
    cin >> test;
    while(test--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << dp[1][a][b][c] << " " << dp[2][a][b][c] << " " << dp[3][a][b][c] << endl;
    }
    return 0;
}

/*
2 1 10
3 0 9
0 3 6
3 0 3
2 1 2
3 0 1
2 1 0

*/
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

const int maxN = 210;

int n, m;
int dp[maxN][maxN][maxN];
int a[maxN][maxN];

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int res = 0;

bool moveto(int i, int j, int k, int cur){
    if (min(j,k) < 1 or max(j,k) > m){
        return 0;
    }
    // if (j >= k){
    //     return 0;
    // }
    int co = a[i][j];
    if (j != k){
        co += a[i][k];
    }
    int t = maximize(dp[i][j][k], cur + co);
    res = max(res, dp[i][j][k]);
    return t;
}


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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    dp[1][1][m] = a[1][1] + a[1][m];
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= m; k++){
                int cur = dp[i][j][k];
                if (cur == 0){
                    continue;
                }
                for (int d1 = -1; d1 <= 1; d1++){
                    for (int d2 = -1; d2 <= 1; d2++){
                        if (moveto(i + 1, j + d1, k + d2, cur)){
                            // cout << i << " " << j << " " << k << ": " << cur << endl;
                            // cout << "=>" << i + 1 << " " << j + d1 << " " << k + d2 << ": " << dp[i + 1][j + d1][k + d2] << endl;
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
#include"bits/stdc++.h"
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 502;
const int mod = 1e9 + 7;

char a[maxN][maxN];
// int dp[maxN][maxN][maxN];
map<int,map<int,int>> dp[maxN];
pair<ii,ii> d[] = {
    {{1,0}, {1,0}},
    {{1,0}, {0,1}},
    {{0,1}, {1,0}},
    {{0,1}, {0,1}}
};

int get(int i, int j, int u){
    // cout << i << " " << j << " " << i + j - u << endl;
    return dp[i][j][u];
}
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("ppalindrome.inp", "r")) {
        freopen("ppalindrome.inp", "r", stdin);
        freopen("ppalindrome.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (a[1][1] == a[n][n]){
        dp[1][1][1] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int u = 1; u <= n; u++){
                int v = i + j - u;
                if (u <= 0){
                    break;
                }
                int cur = dp[i][j][u];
                if (i > n - u + 1){
                    continue;
                }
                if (cur == 0){
                    continue;
                }
                // cout << i << " " << j << " " << u << " " << v << ": " << cur << endl;
                for (int di = 0; di < 4; di++){
                    int ni = i + d[di].fi.fi;
                    int nj = j + d[di].fi.se;
                    int nu = u + d[di].se.fi;
                    int nv = v + d[di].se.se;
                    if (ni <= n - nu + 1 and nj <= n - nv + 1){
                        if (a[ni][nj] == a[n - nu + 1][n - nv + 1]){
                            (dp[ni][nj][nu] += cur) %= mod;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += get(i, n - i + 1, n + 1 - (i + 1) + 1);
        res += get(i, n - i + 1, n + 1 - i + 1);
        res %= mod;
    }
    cout << res << endl;
    return 0;
}
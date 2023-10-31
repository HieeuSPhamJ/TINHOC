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

const int maxN = 100;

int mod;
int n, m;
char a[maxN][maxN];
int dp[maxN][maxN][maxN][22];
pair <ii,ii> dd[]{
    {{1,0},{-1,0}},
    {{1,0},{0,-1}},
    {{0,1},{-1,0}},
    {{0,1},{0,-1}}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    // if (fopen(".inp", "r")) {
    //     freopen(".inp", "r", stdin);
    //     freopen(".out", "w", stdout);
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> mod;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1][n][(s[1] == a[1][1])] = 1;
    for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
    for (int u = n; u >= 1; u--){
        int v = m - (i + j - (n - u + 1) - 1);
        for (int k = 0; k <= 1; k++){
            int cur = dp[i][j][u][k];
            if (cur == 0){
                continue;
            }
            // cout << i << " " << j << " " << u << " " << v << " " << k << endl;
            for (int d = 0; d < 4; d++){
                ii x = {i,j};
                ii y = {u,v};
                x.fi += dd[d].fi.fi;
                x.se += dd[d].fi.se;
                y.fi += dd[d].se.fi;
                y.se += dd[d].se.se;
                if (x.fi <= y.fi and x.se <= y.se){
                    if (a[x.fi][x.se] == a[y.fi][y.se] and a[x.fi][x.se] != '#'){
                        bool co = k or (a[x.fi][x.se] == s[1]);
                        (dp[x.fi][x.se][y.fi][co] += cur) %= mod;
                        // cout << " =>" << " " << x.fi << " " << x.se << " " << y.fi << " " << y.se << " " << co << endl;
                    }
                }
            }
        }
    }
    }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dp[i][m - i + (n % 2 == 0)][j][1]){
                // cout << i << ' ' << m - i + (n % 2 == 0) << " " << j << " " << dp[i][m - i + (n % 2 == 0)][j][1] << endl;
            }
            (res += dp[i][m - i + (n % 2 == 0)][j][1]) %= mod;
        }
    }
    cout << res << endl;
    return 0;
}

/*
aabc
ab#b
acba
aaaa
*/
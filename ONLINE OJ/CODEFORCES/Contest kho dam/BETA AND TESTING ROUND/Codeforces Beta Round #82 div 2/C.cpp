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

const int maxN = 12;

pair<ii,int> a[maxN];

int dp[12][1010];


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
    int m, n, c0, d0;
    cin >> m >> n >> c0 >> d0;
    for (int i = 1; i <= n; i++){
        int t, b, c, d;
        cin >> t >> b >> c >> d;
        t /= b;
        a[i] = {{t,c},d};
    }

    for (int i = 1; i * c0 <= m; i++){
        dp[0][i * c0] = d0 * i;
    }
    for (int i = 1; i <= m; i++){
        maximize(dp[0][i], dp[0][i - 1]);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            maximize(dp[i][j], dp[i - 1][j]);
            maximize(dp[i][j], dp[i][j - 1]);
            for (int k = 1; k <= a[i].fi.fi; k++){
                if (j - k * a[i].fi.se >= 0){
                    maximize(dp[i][j], dp[i - 1][j - k * a[i].fi.se] + k * a[i].se);
                }
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}
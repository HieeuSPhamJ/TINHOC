#include"bits/stdc++.h"
#define int long long
// #define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 110;

ii a[maxN];
int dp[510][maxN];

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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SELL.inp", "r")) {
        freopen("SELL.inp", "r", stdin);
        freopen("SELL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, K;
    cin >> n >> K;
    K = min(K, n - K);
    int total = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
        total += a[i].fi;
    }
    int price = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
        price += a[i].se;
    }
    for (int i = 0; i <= total; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = total; j >= a[i].fi; j--){
            for (int k = K; k >= 1; k--){
                minimize(dp[j][k], dp[j - a[i].fi][k - 1] + a[i].se);
                // cout << i << ' ' << j << " " << k << ": " << dp[j][k] << endl;
            }
        }
    }

    double res = 1e18;
    for (int i = 1; i <= total; i++){
        if (dp[i][K] != 1e18 and dp[i][K] != 0){
            double tu = (double) dp[i][K] * (price - dp[i][K]);
            double mau = (double) i * (total - i);
            res = min(res, tu / mau);
            // cout << k << " " << i << "/" << dp[i][k] << " " << total - i << "/" << price - dp[i][k] << endl;
        }
    }

    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

/*
a * c
-----
b * d

a * (sum - a)
------------
b * (price - b)

-a^2 + a*sum
------------
-b^2 + b*price 


*/
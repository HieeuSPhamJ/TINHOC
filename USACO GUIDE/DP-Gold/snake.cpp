#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 400 + 10;

int a[maxN];
int dp[maxN][maxN];

signed main(){
    // freopen("snakes.in", "r", stdin);
    // freopen("snakes.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    for (int d = 1; d <= k + 1; d++){
        for (int i = 1; i <= n; i++){
            dp[d][i] = 1e18;
        }
    }

    for (int i = 1, ma = 0, sum = 0; i <= n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        sum += a[i];
        dp[1][i] = ma * i - sum;
    }


    for (int d = 2; d <= k + 1; d++){
        for (int i = d; i <= n; i++){
            for (int j = 1, ma = 0, sum = 0; i - j >= 0; j++){
                ma = max(ma, a[i - j + 1]);
                sum += a[i - j + 1];
                dp[d][i] = min(dp[d][i], dp[d - 1][i - j] + ma * j - sum);
            }
        }
    }

    cout << dp[k + 1][n];

    return 0;
}
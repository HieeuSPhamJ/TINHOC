#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e4 + 10;

double dp[maxN][maxN];
double a[maxN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        dp[0][i] = 1;
        cin >> a[i];
        dp[i][1] = a[i];
        dp[i][0] = 1.0 - a[i]; 
        // cout << a[i] << ' ';
    }
    // cout << endl;


    for (int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][0] * (1.0 - a[i]);
        for (int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1.0 - a[i]);
            // cout << dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1.0 - a[i]) << endl;
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }

    double ans = 0;

    for (int i = (n / 2) + 1; i <= n; i++){
        ans += dp[n][i];
    }
    

    cout << fixed << setprecision(10) << ans;

    return 0;
}


/*
    dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i])
*/
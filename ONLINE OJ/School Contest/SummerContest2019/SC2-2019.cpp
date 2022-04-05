#include<bits/stdc++.h>
using namespace std;

const int maxN = 3001;

int a[maxN];
int b[maxN];
int dp[maxN][maxN];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= max(n, m); i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]){
                // if (i - 1 >= 0 and j - 1 >= 0){
                //     dp[i][j] = max(dp[i][j], dp[i - 2][i - 2] + 1);
                // }
                dp[i][j] = max(dp[i][j], dp[max(i - 2, 0)][max(j - 2, 0)] + 1);
            }
        }
    }
    cout << dp[n][m];
    cout << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }

    return 0;
}
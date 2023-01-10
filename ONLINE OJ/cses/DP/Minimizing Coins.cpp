#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[maxN];
int a[maxN];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        dp[i] = 1e9;
    }

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (i - a[j] >= 0){
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if (dp[m] == 1e9){
        cout << -1;
        return 0;
    }

    cout << dp[m];
    return 0;
}
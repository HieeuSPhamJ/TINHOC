#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[maxN];
int a[maxN];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dp[0] = 1;

    // cout << "-";
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (i - a[j] >= 0){
                // cout << i - j;
                (dp[i] += dp[i - a[j]]) %= mod;
            }
        }
        // dp[i]++;
        // cout << dp[i] << endl;
    }

    cout << dp[m];
    
    return 0;
}
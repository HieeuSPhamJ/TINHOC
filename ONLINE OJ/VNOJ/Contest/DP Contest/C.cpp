#include<bits/stdc++.h>
using namespace std;

const int inf = -1e9;
const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];
int c[maxN];

int dp[maxN][4];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for (int i = 2; i <= n; i++){
        dp[i][1] = a[i] + max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = b[i] + max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = c[i] + max(dp[i - 1][1], dp[i - 1][2]);
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
    

    

    return 0;
}
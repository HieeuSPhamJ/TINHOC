#include <bits/stdc++.h>
using namespace std;

int dp[100010];

int main(){
    int test;
    cin >> test;
    while (test--){
        int a, b, n;
        cin >> n >> a >> b;
        dp[1] = a;
        for (int i = 2; i <= n; i++){
            if (i % 2 == 0){
                dp[i] = min(dp[i - 1] + a, dp[i / 2] + b);
            }
            else{
                dp[i] = dp[i - 1] + a;
            }
        }
        cout << dp[n];
        cout << endl;
    }

    return 0;
}
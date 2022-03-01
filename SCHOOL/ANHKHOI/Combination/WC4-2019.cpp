#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;
int dp[maxN][maxN];


int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            dp[i][0] = 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; i++){
                int temp = dp[i][j - 1];
                if (i > j){
                    dp[i][j] = dp[i - 1][j - 1] + temp;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            ans += dp[n][i];
        }
        cout << n;

    
    }


    return 0;
}
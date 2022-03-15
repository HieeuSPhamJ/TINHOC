#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;
int dp[maxN][maxN];
int n;

void check(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "===========" << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            dp[1][i] = 1;
            dp[i][0] = 1;
        }
        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j - 1];
                if (j > i){
                    dp[i][j] = dp[i][j] * 2 + 1;
                }
                check();
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            ans += dp[i][n];
        }
        cout << ans;
        cout << endl;
    
    }


    return 0;
}
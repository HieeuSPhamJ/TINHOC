#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    long long dp[n + 10][k][k];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int y = 0; y <= k; y++){
                dp[i][j][y]  = 0;
            }
        }
    }    

    dp[1][1][0] = dp[1][0][0] = dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++){
        for (int numOne = 0; numOne <= i; numOne++){
            for (int len = 0; len <= numOne; len++){
                int now = dp[i][numOne][len];
                if (now == 0){
                    continue;
                }
                for (int dig = 0; dig <= 1; dig++){
                    if (dig == 0){
                        dp[i + 1][numOne][0] += now;
                    }
                    else{
                        dp[i + 1][numOne + 1][len + 1] += now;
                    }
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j < k; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    long long ans = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < k; j++){
            ans += dp[n][i][j];
        }
    }

    cout << ans;

    return 0;
}

/*

*/
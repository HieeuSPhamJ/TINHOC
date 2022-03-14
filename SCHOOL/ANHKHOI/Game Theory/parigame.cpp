#include<bits/stdc++.h>
using namespace std;

const int maxN = 510;

long long a[maxN][maxN];
int dp[maxN][maxN];
long long sumCot[maxN][maxN];
long long sumHang[maxN][maxN];

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++){
            sumCot[0][i] = 0;
            sumHang[i][0] = 0;
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
                sumCot[i][j] = a[i][j] + sumCot[i - 1][j];
                sumHang[i][j] = a[i][j] + sumHang[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i == 1 and j == 1){
                    if (a[i][j] % 2 == 0){
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                    if (sumCot[i][j] % 2 == 0 and dp[i][j - 1] == 0){
                        dp[i][j] = 1;
                    }
                    if (sumHang[i][j] % 2 == 0 and dp[i - 1][j] == 0){
                        dp[i][j] = 1;
                    }
                }
            }
        }
        // cout << "SUMCOT" << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= n; j++){
        //         cout << sumCot[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        
        // cout << "SUMHANG" << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= n; j++){
        //         cout << sumHang[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        
        // cout << "DP" << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= n; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        if (dp[n][n] == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }

        cout << endl;
    }


    return 0;
}
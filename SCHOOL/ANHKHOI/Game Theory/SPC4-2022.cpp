#include<bits/stdc++.h>
using namespace std;

const int maxN = 30;

int a[maxN];
int dp[maxN][maxN][maxN];
int sum[maxN];

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, k , t;
        cin >> n >> k >> t;
        sum[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        for (int x = 0; x <= n; x++){
            for (int y = 0; y <= max(t, k); y++){
                for (int z = 0; z <= max(t, k); z++){
                    dp[x][y][z] = 0;
                }
            }
        }
        for (int x = 1; x <= n; x++){
            for (int y = 0; y <= max(t, k); y++){
                for (int z = 0; z <= max(t, k); z++){
                    for (int temp = 0; temp <= min(y, x - 1); temp++){
                        dp[x][y][z] = max(dp[x][y][z], sum[x] - dp[x - temp - 1][z][y - temp]);
                    }
                }
            }
        }
        if (dp[n][k][t] == sum[n] - dp[n][k][t]){
            cout << "DRAW";
        }
        else if (dp[n][k][t] < sum[n] - dp[n][k][t]){
            cout << "LOSE";
        }
        else{
            cout << "WIN";
        }
        cout << endl;

    }

    return 0;
}
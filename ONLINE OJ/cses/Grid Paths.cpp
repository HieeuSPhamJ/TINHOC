#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e3 + 10;

int a[maxN][maxN];
int dp[maxN][maxN];


main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char inp;
            cin >> inp;
            if (inp == '*'){
                a[i][j] = 1;
            }
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i - 1][j] != 1){
                dp[i][j] += dp[i - 1][j];
            }
            if (a[i][j - 1] != 1){
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }

    if (a[1][1] == 1 or a[n][n] == 1){
        cout << 0;
        return 0;
    }

    cout << dp[n][n];

    return 0;
}
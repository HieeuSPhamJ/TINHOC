#include<bits/stdc++.h>
#define int long long
using namespace std;

unordered_map <int,int> dp;


main(){
    int n, m, h;
    cin >> n >> m >> h;

    for (int i = 1; i <= h; i++){
        int a, b;
        cin >> a >> b;
        dp[a][b] = -1;
    }

    dp[1][1] = 1;
    int x = 1;
    int y = 1;
    int maxX = n;
    int maxY = m;
    for (int i = x; i <= maxX; i++){
        for (int j = y; j <= maxY; j++){
            if (dp[i + 1][j] == -1){
                break;
            }
            if (dp[i][j] != -1){
               if (dp[i - 1][j] != -1){
                   dp[i][j] += dp[i - 1][j];
               }
               if (dp[i][j - 1] != -1){
                   dp[i][j] += dp[i][j - 1];
               }
            }
        }
    }



    return 0;
}


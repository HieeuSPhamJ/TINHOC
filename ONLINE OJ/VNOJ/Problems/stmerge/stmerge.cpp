#include<bits/stdc++.h>
using namespace std;

const int maxNM = 1e3 + 10;
const int inf = 1e9;

int a[maxNM][maxNM];
int dp[maxNM][maxNM][3];

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int e = 1; e <= m; e++){
                cin >> a[i][e];
            }
        }
        for (int i = 0; i <= max(n, m); i++){
            dp[i][0][1] = inf;
            dp[i][0][0] = 0;
            dp[0][i][0] = inf;
            dp[0][i][1] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int e = 1; e <= m; e++){
                dp[i][e][0] = min(dp[i - 1][e][0], dp[i - 1][e][1] + a[i][e]);
                dp[i][e][1] = min(dp[i][e - 1][1], dp[i][e - 1][0] + a[i][e]);
            }
        }
        for (int i = 1; i <= n; i++){
            for (int e = 1; e <= m; e++){
                cout << dp[i][e][0] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 1; i <= n; i++){
            for (int e = 1; e <= m; e++){
                cout << dp[i][e][1] << ' ';
            }
            cout << endl;
        }

        cout << min(dp[n][m][0], dp[n][m][1]);
        cout << endl;
    }


    return 0;
}
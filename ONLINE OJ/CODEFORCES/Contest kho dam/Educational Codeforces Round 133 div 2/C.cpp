#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[3][maxN];
int dp[3][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int m;
        cin >> m;
        for (int i = 1; i <= 2; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int ans = 1e18;
        
        dp[1][1] = 0;
        dp[2][1] = a[2][1];
        if (a[2][1] == 0){
            dp[2][1] = 1;
        }
        for (int i = 2; i <= m; i++){
            if (i % 2 == 0){
                if (dp[2][i - 1] + 1 >= a[2][i - 1]){
                    dp[2][i] = dp[2][i - 1] + 1;
                }
                else{
                    dp[2][i] = a[2][i] + 1;
                }
                if (dp[2][i] + 1 >= a[1][i]){
                    dp[1][i] = dp[2][i] + 1;
                }
                else{
                    dp[1][i] = a[1][i] + 1;
                }
            }
            else{
                if (dp[1][i - 1] + 1 >= a[1][i - 1]){
                    dp[1][i] = dp[1][i - 1] + 1;
                }
                else{
                    dp[1][i] = a[1][i] + 1;
                }
                if (dp[1][i] + 1 >= a[2][i]){
                    dp[2][i] = dp[1][i] + 1;
                }
                else{
                    dp[2][i] = a[1][i] + 1;
                }
            }
        }

        for (int i = 1; i <= 2; i++){
            for (int j = 1; j <= m; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }

        int left = 



        cout << ans << endl;
    }
    
    return 0;
}
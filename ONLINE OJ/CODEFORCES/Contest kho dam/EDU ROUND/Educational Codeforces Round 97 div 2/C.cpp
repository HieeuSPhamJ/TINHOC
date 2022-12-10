#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 410;

int a[maxN];
int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        sort(a + 1, a + 1 + n);

        for (int time = 1; time <= 2 * n; time++){
            for (int i = 1; i <= n; i++){
                dp[time][i] = 1e18;
                if (i == 1){
                    // cout << time << ": " << a[i] << 
                    dp[time][i] = abs(time - a[i]);
                }
            }
        }

        // for (int i = 1; i <= n; i++){
        //     cout << a[i] << ' ';
        // }
        // cout << endl;

        for (int time = 1; time <= 2 * n; time++){
            for (int i = 2; i <= n; i++){
                for (int preTime = 1; preTime < time; preTime++){
                    dp[time][i] = min(dp[time][i], dp[preTime][i - 1] + abs(a[i] - time));
                }
            }
        }

        int ans = 1e18;

        // for (int i = 0; i <= 2 * n; i++){
        //     for (int j = 0; j <= n; j++){
        //         if (dp[i][j] == 1e18){
        //             cout << "~" << " ";
        //             continue;
        //         }
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 1; i <= 2 * n; i++){
            ans = min(ans, dp[i][n]);
        }

        cout << ans << endl;

    }

    return 0;
}
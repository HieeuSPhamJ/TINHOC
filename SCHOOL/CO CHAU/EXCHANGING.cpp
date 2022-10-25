#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;

int a[100];
int dp[14][10010];

signed main(){
    freopen("EXCHANGING.INP", "r", stdin);
    freopen("EXCHANGING.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= 10010; j++){
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        // cout << "Index: " << i << endl;
        for (int pro = 0; pro <= 10010; pro++){
            // cout << "Produce: " << pro << endl;
            int now = dp[i][pro];
            if (now != inf){
                for (int b = 1; b * b + pro <= m; b++){
                    // cout << b * b << " ";
                    dp[i + 1][pro + b * b] = min(dp[i + 1][pro + b * b], now + (a[i + 1] - b) * (a[i + 1] - b));
                }
            }
            // cout << endl;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= 10; j++){
    //         if (dp[i][j] == inf){
    //             cout << -1 << " ";
    //             continue;
    //         }
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (dp[n][m] != inf){
        cout << dp[n][m];
    }
    else{
        cout << -1;
    }

    return 0;
}
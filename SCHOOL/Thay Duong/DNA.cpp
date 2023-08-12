#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int dp[maxN][3];

signed main(){
    freopen("DNA.INP", "r", stdin);
    freopen("DNA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a[0] = -1;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - 'A';
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 1; j++){        
            dp[i][j] = 1e18;
        }
    }
    dp[1][a[1]] = 0;
    dp[1][!a[1]] = 1;
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 1; j++){
            int cur = dp[i][j];
            if (cur == 1e18){
                continue;
            }
            // cout << i << " " << j << " " << dp[i][j] << ": ";
            if (a[i + 1] == j){
                // cout << "same" << endl;
                dp[i + 1][j] = min(dp[i + 1][j], cur);
                dp[i + 1][!j] = min(dp[i + 1][!j], cur + 1);
            }
            else{
                // cout << "diff" << endl;
                dp[i + 1][j] = min(dp[i + 1][j], cur + 1);
                dp[i + 1][!j] = min(dp[i + 1][!j], cur + 1);
            }
        }
    }

    // for (int j = 0; j <= 1; j++){
    //     for (int i = 1; i <= n; i++){
    //         if (dp[i][j] == 1e18){
    //             cout << "* ";
    //             continue;
    //         }
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][0];

    return 0;
}

/*
0
1
*/
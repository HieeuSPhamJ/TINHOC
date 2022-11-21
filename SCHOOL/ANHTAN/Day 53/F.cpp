#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[210][210];
int dp[210][210];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            dp[i][j] = 1e18;
        }
    }

    dp[1][1] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j and i != 1 and j != 1){
                continue;
            }
            int k = max(i,j) + 1; 
            dp[i][k] = min(dp[i][k], dp[i][j] + a[j][k]);
            dp[k][j] = min(dp[k][j], dp[i][j] + a[i][k]);
        }
    }

    int ans = 1e18;
    for (int i = 1; i < n; i++){
        int temp = (dp[i][n], dp[n][i]);
        // cout << i << " " << n << " " << temp << " " << a[i][1] << " " << a[n][1] << endl;
        ans = min(ans, temp + a[i][1] + a[n][1]);
    }
    cout << ans;
    return 0;
}

/*
1 2 3 4
* * 
*   *
*/
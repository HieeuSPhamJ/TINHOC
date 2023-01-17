#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string a;

int dp[310][310][310];

int cal(int l, int r, int k){
    if (dp[l][r][k] != -1){
        return dp[l][r][k];
    }
    if (k < 0 or l > r){
        return 0;
    }
    if (l == r){
        // cout << l << " " << r << " " << k << ": " << 1 << endl;
        dp[l][r][k] = 1;
        return dp[l][r][k];
    }
    if (l + 1 == r){
        if (k == 0){    
            dp[l][r][k] = 1 + (a[l] == a[r]);
            // cout << l << " " << r << " " << k << ": " << dp[l][r][k] << endl;
            return dp[l][r][k];
        }
        // cout << l << " " << r << " " << k << ": " << 2 << endl;
        dp[l][r][k] = 2;
        return dp[l][r][k];
    }
    
    dp[l][r][k] = max(dp[l][r][k], cal(l + 1,r - 1,k) + 2 * (a[l] == a[r]));
    dp[l][r][k] = max(dp[l][r][k], cal(l + 1,r,k));
    dp[l][r][k] = max(dp[l][r][k], cal(l,r - 1,k));
    if (k >= 1){
        dp[l][r][k] = max(dp[l][r][k], cal(l + 1,r - 1,k - 1) + 2);
        dp[l][r][k] = max(dp[l][r][k], cal(l + 1,r,k - 1));
        dp[l][r][k] = max(dp[l][r][k], cal(l,r - 1,k - 1));
    }
    // cout << l << " " << r << " " << k << ": " << dp[l][r][k] << endl;
    return dp[l][r][k];

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n, k;
    cin >> a;
    cin >> k;
    n = a.length() - 1;
    // for (int i = 0; i <= n; i++){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    cout << endl;
    cout << cal(0,n,k);
    return 0;
}

/*
0 1 2 3 4 5 6 7 
a b c a b c a b 
*/
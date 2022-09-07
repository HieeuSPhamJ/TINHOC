#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int a[25200];
int dp[25200];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> a[i];
    }

    if (n <= 3){
        cout << a[1] + a[2];
        return 0;
    }

    dp[2] = a[1];
    dp[3] = a[1] + a[2];

    for (int i = 4; i <= n; i++){
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 1]);
        // cout << dp[i - 2] << " " << dp[i - 1] << " " << dp[i] << endl;
    }
    
    cout << dp[n];

    
    return 0;
}
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
int sum[maxN];

int s(int i, int j){
    return (sum[j] - sum[i - 1]);
}

int solve(int i, int j){
    if(i == j or i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 1e18;

    for(int x=i;x<j;x++){
        ans = min(ans, solve(i,x)+solve(x+1,j)+s(i,j));
    }
    dp[i][j] = ans;

    return dp[i][j];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    memset(dp,-1,sizeof(dp));

    cout << solve(1,n);
    return 0;
}

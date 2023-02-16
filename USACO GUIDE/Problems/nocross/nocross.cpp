#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;

int n;
int a[maxN];
int b[maxN];
int dp[maxN][maxN];

int cal(int i, int j){
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    if (i > n or j > n){
        return 0;
    }
    int now = max({cal(i,j + 1), cal(i + 1,j)});
    if (abs(a[i] - b[j]) <= 4){
        now = max(now,cal(i + 1,j + 1) + 1);
    }
    dp[i][j] = now;
    // cout << i << " " << j << " " << dp[i][j] << endl;
    return now;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << cal(1,1);
    return 0;
}
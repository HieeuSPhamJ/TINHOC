#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

 int n, m;
int dp[40010];
int pre[40010];

int sum(int i, int j){
    return (pre[j + 1] - pre[i] + mod) % mod;
}

signed main(){
    freopen("ORDER.INP", "r", stdin);
    freopen("ORDER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> m;
    dp[0] = 1;

    for (int i = 2; i <= n; i++){
        pre[1] = dp[0];
        for (int j = 1; j <= m; j++){
            pre[j + 1] = (pre[j] + dp[j]) % mod;
        }
        for (int j = 0; j <= m; j++){
            int k = i - 1;
            dp[j] = sum(max(0, j - k), j);
        }
    }

    cout << dp[m] << endl;
    return 0;
}
/*
12
*/
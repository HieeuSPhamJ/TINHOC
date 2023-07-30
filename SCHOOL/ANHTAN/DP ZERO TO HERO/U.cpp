#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define nu 0
#define nam 1
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[2][maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    dp[nu][0] = 1;
    for (int i = 1; i <= n; i++){
        dp[nu][i] = dp[nu][i - 1] + dp[nam][i - 1];
        dp[nam][i] = 1;
        if (i - k - 1 >= 0){
            dp[nam][i] += pre[i - k - 1];
        }
        dp[nu][i] %= mod;
        dp[nam][i] %= mod;
        pre[i] = pre[i - 1] + dp[nam][i];
        pre[i] %= mod;
    }

    cout << (dp[nu][n] + dp[nam][n]) % mod << endl;
    return 0;
}
/*
1 2 3 4 5
*     *

0
1

*/
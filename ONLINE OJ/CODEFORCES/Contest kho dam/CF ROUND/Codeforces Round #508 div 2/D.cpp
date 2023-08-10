#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

int dp[maxN][3][5];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        dp[i][0] = min(dp[i - 1][0] - x, x - dp[i - 1][0]);
        dp[i][1] = max(x - dp[i - 1][0], dp[i - 1][1] - x);
        dp[i][2] = min(dp[i - 1][0] - x, )
    }   
    return 0;
}
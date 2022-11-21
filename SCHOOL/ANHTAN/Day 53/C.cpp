#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int dp[maxN];

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
    dp[2] = a[1];
    dp[3] = a[2] + dp[2];
    for (int i = 4; i <= n; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i - 1];
    }
    cout << dp[n];
    return 0;
}
/*
1 2 3 4 5 6
0 2 2
*/
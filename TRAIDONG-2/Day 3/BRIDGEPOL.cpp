#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int h[maxN];
int w[maxN];
int dp[maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("BRIDGEPOL.inp", "r")) {
        freopen("BRIDGEPOL.inp", "r", stdin);
        freopen("BRIDGEPOL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        dp[i] = 1e18;
        pre[i] = pre[i - 1] + w[i];
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = i - 1; j >= 1; j--){
            dp[i] = min(dp[i], dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + pre[i - 1] - pre[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
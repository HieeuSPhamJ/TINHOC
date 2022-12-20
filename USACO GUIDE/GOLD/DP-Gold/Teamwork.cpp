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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1, mi = a[i]; j <= k and i - j >= 0; j++){
            mi = max(mi, a[i - j + 1]);
            dp[i] = max(dp[i], dp[i - j] + mi * j);
        }
    }

    cout << dp[n];

    return 0;
}
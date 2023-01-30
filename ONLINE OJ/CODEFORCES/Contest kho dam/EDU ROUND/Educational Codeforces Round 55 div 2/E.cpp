#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 10;

int a[maxN];

int dp[maxN];
int ddp[maxN];
int precon[maxN];
int minpre[maxN];


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
        precon[i] = precon[i - 1] + (a[i] == k);
    }

    for (int i = 1; i < maxN; i++){
        minpre[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        dp[i] = ddp[a[i]] + 1;
        ddp[a[i]] = dp[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int res = precon[n] - precon[i];
        minpre[a[i]] = max(minpre[a[i]], precon[i - 1] - (dp[i] - 1));
        
        res += dp[i] + minpre[a[i]];

        ans = max(ans, res);    
    }

    cout << ans << endl;

    return 0;
}
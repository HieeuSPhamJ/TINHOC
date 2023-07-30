#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int p[maxN];
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
        p[i] = p[i - 1] + a[i];
        dp[i] = max(dp[i - 1], 0ll) + a[i];
    }
    int res = -1e18;
    for (int i = 1; i <= n; i++){
        if (i + k - 1 > n){
            break;
        }
        int t = dp[i] + p[i + k - 1] - p[i];
        // cout << i << " " << i + k - 1 << ": " << t << endl;
        res = max(res, t);
    }

    cout << res << endl;
    return 0;
}

/*
1 2 3 4 5 6 7 8
  * 
*/

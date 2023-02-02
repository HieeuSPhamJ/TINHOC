#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;

int a[maxN];
int dp[maxN][maxN];

int cal(int l, int r){
    if (dp[l][r] != 1e18){
        // cout << l << " " << r << " " << dp[l][r] << endl;
        return dp[l][r];
    }
    if (l == r){
        // cout << l << " " << r << " " << 0 << endl;
        return dp[l][r] = 0;
    }
    if (l + 1 == r){
        // cout << l << " " << r << " " << (a[l] != a[r]) << endl;
        return dp[l][r] = (a[l] != a[r]);
    }

    dp[l][r] = min({
                    cal(l,r - 1) + (a[r] != a[r - 1]),
                    cal(l + 1,r) + (a[l] != a[l + 1]),
                    cal(l + 1,r - 1) + (a[l] != a[r]) + (a[l] != a[l + 1] or a[r] != a[r - 1])
                });
    
    // cout << l << " " << r << " " << dp[l][r] << endl;
    return dp[l][r];
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
        for (int j = 1; j <= n; j++){
            dp[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << cal(1,n);
    return 0;
}
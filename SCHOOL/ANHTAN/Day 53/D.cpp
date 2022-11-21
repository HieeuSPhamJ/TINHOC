#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[1010];
int dp[100][10010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int maxS = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxS += a[i];
    }   
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int s = 0; s <= maxS; s++){
            int now = dp[i][s];
            if (now == 0){
                continue;
            }
            // cout << "With: " << i << " " << s << " " << now << endl;
            for (int x = 1; x <= a[i + 1]; x++){
                dp[i + 1][s + x] += now;
                // cout << i + 1 << " " << s + x << endl;
            }
        }
    }
    ii ans = {0,0};
    for (int i = 0; i <= maxS; i++){
        // cout << i << " " << dp[n][i] << endl;
        if (dp[n][i] > ans.fi){
            ans.se = i;
            ans.fi = dp[n][i];
        }
    }

    cout << ans.se;

    return 0;
}

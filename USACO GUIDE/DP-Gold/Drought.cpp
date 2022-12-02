#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int a[110];
int dp[110][1010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= min(a[1], a[2]); i++){
        dp[2][i] = 1;
    }

    for (int i = 3; i <= n; i++){
        for (int h = 0; h <= a[i]; h++){
            for (int k = h; k <= a[i - 1]; k++){
                dp[i][h] += dp[i - 1][k];
                dp[i][h] %= mod;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= a[i]; j++){
            cout << dp[i][j] << " ";
            if (dp[i][j] < 10){
                cout << " ";
            }
        }
        cout << endl;
    }

    int ans = 0;

    for (int i = 0; i <= a[n]; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    
    cout << ans;

    return 0;
}
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
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN][maxN];
int cnt[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 0; j <= 5001; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j <= 5001; j++){
            (dp[i][min(5001ll,j + a[i])] += dp[i - 1][j]) %= mod;
        }
    }

    
    // for (int j = 0; j <= 8; j++){
    //     cout << j << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= 8; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = 0;
    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        for (int j = a[i] + 1; j <= 5001; j++){
            // cout << j << " " << dp[i][j] - cnt[j] << endl;
            (res += dp[i - 1][j] - cnt[j] + mod) %= mod;
        }
        cnt[a[i]]++;
    }
    cout << res << endl;
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 110;
const int inf = 1e18;

int n;
int a[maxN];
int dp[maxN][maxN];
int cnt[maxN];

void init(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = inf;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int k = 1; k <= n; k++){
        init();
        int ans = inf;
        for (int i = 1; i <= n; i++){
            for (int j = i - 1; j >= 1; j--){
                dp[d][i] = min(dp[d][i], dp[d - 1][j] + cnt[j]);
            }
            dp[d][i] += (a[i] == 0);
            cnt[i - a[i]]++;
            if (d == k){
                ans = min(ans, dp[d][i]);
            }
        }
        for (int d = 2; d <= k; d++){
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= n; i++){
                for (int j = i - 1; j >= 1; j--){
                    dp[d][i] = min(dp[d][i], dp[d - 1][j] + cnt[j]);
                }
                dp[d][i] += (a[i] == 0);
                cnt[i - a[i]]++;
                if (d == k){
                    ans = min(ans, dp[d][i]);
                }
            }
        }
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << ans << endl;
    } 
    return 0;
}
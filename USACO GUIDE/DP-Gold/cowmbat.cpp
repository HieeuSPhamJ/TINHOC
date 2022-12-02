#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

int a[maxN];
int trans[30][30];
int ans[maxN];
int dp[maxN][30];
int prefix[maxN][30];

int cal(int l, int r, int t){
    return prefix[r][t] - prefix[l - 1][t];
}

signed main(){
    //freopen("cowmbat.in", "r", stdin);
    //freopen("cowmbat.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - 'a' + 1;
        ans[i] = inf;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            cin >> trans[i][j];
        }
    }

    for (int k = 1; k <= m; k++){
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= m; j++){
                trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
            }
        }
    }


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 26; j++){
            dp[i][j] = inf;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            prefix[i][j] = prefix[i - 1][j] + trans[a[i]][j];
        }
    }

    for (int i = 1; i <= m; i++){
        dp[k][i] = cal(1,k,i);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int now = dp[i][j];
            if (now == inf){
                continue;
            }
            dp[i + 1][j] = min(dp[i + 1][j], now + trans[a[i + 1]][j]);
            if (i + k <= n){
                for (int nj = 1; nj <= m; nj++){
                    dp[i + k][nj] = min(dp[i + k][nj], now + cal(i + 1, i + k, nj));
                }
            }
            ans[i] = min(ans[i], dp[i][j]);
        }
    }

    // for (int j = 1; j <= m; j++){
    //     for (int i = 1; i <= n; i++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << ans[n];

    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 310;

vector <ii> chars[40];

int a[maxN];
int dp[maxN][maxN * maxN];

int calCost(ii x, ii y){
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        char inp;
        cin >> inp;
        a[i] = inp - 'A';
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char inp;
            cin >> inp;
            chars[inp - 'A'].push_back({i,j});
        }
    }

    for (int i = 2; i <= k; i++){
        for (int j = 0; j < (int)chars[a[i]].size(); j++){
            dp[i][j] = 1e18;
            for (int last = 0; last < (int)chars[a[i - 1]].size(); last++){
                if (chars[a[i]][j] == chars[a[i - 1]][last]){
                    continue;
                }
                int cost = calCost(chars[a[i]][j], chars[a[i - 1]][last]);
                dp[i][j] = min(dp[i][j], dp[i - 1][last] + cost);
            }
        }
    }

    // for (int i = 1; i <= k; i++){
    //     cout << char(a[i] + 'A') << ": ";
    //     for (int j = 0; j < (int)chars[a[i]].size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 1e18;

    for (int i = 0; i < (int)chars[a[k]].size(); i++){
        ans = min(ans, dp[k][i]);
    }

    cout << ans + 1;

    return 0;
}
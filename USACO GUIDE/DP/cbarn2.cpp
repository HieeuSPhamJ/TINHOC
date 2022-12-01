#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;

int n, k;
int dp[110][110][10];

void init(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int d = 0; d <= k; d++){
                dp[i][j][d] = inf;
            }
        }
    }
}

signed main(){
    // freopen("cbarn2.in", "r", stdin);
    // freopen("cbarn2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    deque <int> a;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        a.push_back(inp);
        // cout << a.back() << " ";
    }
    // cout << endl;


    int ans = inf;

    for (int test = 1; test <= n; test++){
        init();
        // cout << "TEST: ";
        // for (auto i: a){
        //     cout << i << " ";
        // }
        // cout << endl;

        dp[0][0][1] = 0;

        for (int d = 1; d <= k; d++){
            for (int open = d - 1; open < n; open++){
                int now = dp[open][open][d];
                if (now == inf){
                    continue;
                }
                // cout << "Dem:" << d << " Open:" << open << " " << now << endl; 
                for (int i = open + 1, sum = 0; i < n; i++){
                    sum += a[i] * (i - open);
                    // cout << "Open:" << open << " " << i << " " << dp[open][i][d] << endl;
                    // if (dp[open][i][d] > now + sum){
                    //     cout << "Change: " << now + sum << endl;
                    // }
                    dp[open][i][d] = min(dp[open][i][d], now + sum);
                    // cout << "New open:" << i << " " << dp[i][i][d + 1] << endl;
                    // if (dp[i][i][d + 1] > sum - a[i] * (i - open)){
                    //     cout << "Change: " << sum - a[i] * (i - open) << endl;
                    // }
                    dp[i][i][d + 1] = min(dp[i][i][d + 1], now + sum - a[i] * (i - open));
                }

                // for (int i = 0; i < n; i++){
                //     if (dp[open][i][d] == inf){
                //         cout << -1 << " ";
                //         continue;
                //     }
                //     cout << dp[open][i][d] << " ";
                // }
                // cout << endl;
            }
        }

        // cout << endl;
        
        for (int i = 0; i < n; i++){
            ans = min(ans, dp[i][n - 1][k]);
        }

        a.push_front(a.back());
        a.pop_back();
    }

    cout << ans;
    return 0;
}


/*
    dp[open][i][d]
    min(dp[preOpen][j][d - 1], dp[open][j][d] + 
*/
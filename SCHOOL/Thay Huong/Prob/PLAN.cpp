#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

ii st[20010];
ii hs[1010];
int dp[1010][20010];
int pre[1010][20010];

void up(int &a, int b){
    a = min(a,b);
}
signed main(){
    // freopen("PLAN.INP", "r", stdin);
    // freopen("PLAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> st[i].fi >> st[i].se;
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> hs[i].fi >> hs[i].se;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i - 1][0] + hs[i].fi * hs[i].se;
        pre[i][0] = dp[i][0];
        for (int j = 1; j <= m; j++){   
            if (st[j].fi <= hs[i].fi){
                int cost = (hs[i].fi - st[j].fi) * hs[i].se;
                up(dp[i][j], dp[i - 1][j] + cost);
                up(dp[i][j], pre[i - 1][j - 1] + st[j].se + cost);
            }
        }
        for (int j = 1; j <= m; j++){   
            pre[i][j] = min(pre[i][j - 1], dp[i][j]);
        }
    }   

    for (int i = 1; i <= n; i++){
        cout << pre[i][m] << " ";
    }
    cout << endl;

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= m; j++){
    //         if (dp[i][j] == 1e18){
    //             cout << "*" << " ";
    //             continue;
    //         }
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    return 0;
}

/*
dp[i][j]: số tiền nhỏ nhất để cho i thằng đầu về nhà với trạm bus cuối là j
dp[i][j] = dp[i - 1][j] + (hs[i].fi - st[j].fi) * hs[i].se
dp[i][j] = dp[i - 1][k] + (hs[i].fi - st[j].fi) * hs[i].se + st[j].se

*/
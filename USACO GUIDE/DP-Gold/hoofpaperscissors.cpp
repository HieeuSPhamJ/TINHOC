#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'

using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
// int prefix[4][maxN];
int dp[maxN][25][4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        if (x == 'P'){
            a[i] = 0;
        }
        if (x == 'H'){
            a[i] = 1;
        }
        if (x == 'S'){
            a[i] = 2;
        }
        // prefix[0][i] = prefix[0][i - 1];
        // prefix[1][i] = prefix[1][i - 1];
        // prefix[2][i] = prefix[2][i - 1];
        // prefix[a[i]][i]++;
    }   

    int ans = 0;

    for (int i = 1; i <= n; i++){
        for (int turn = 0; turn <= k; turn++){
            for (int type = 0; type <= 2; type++){
                int check = + ((type + 1) % 3 == a[i]);
                int tans = dp[i - 1][turn][type] + check;
                if (turn >= 1){
                    tans = max(tans, (dp[i - 1][turn - 1][(type + 1) % 3]) + check);
                    tans = max(tans, (dp[i - 1][turn - 1][(type + 2) % 3]) + check);
                }
                dp[i][turn][type] = tans;
                ans = max(ans, tans);
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][0][2] << "|" << dp[i][1][0] << " " << dp[i][1][1] << " " << dp[i][1][2] << endl;
    // }
    cout << ans;
    return 0;
}
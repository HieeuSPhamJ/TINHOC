#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN][maxN][3];
int cost[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();

    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - '0';
    }

    dp[1][1][1] = 1;

    for (int i = 1; i <= n; i++){
        for (int b = 1; b <= i; b++){
            for (int state = 0; state <= 2; state++){
                int cur = dp[i][b][state];
                if (cur == 0){
                    continue;
                }
                for (int d = 0; d <= 1; d++){
                    int nstate = state;
                    if (nstate == 1){
                        if (d < a[i + 1]){
                            nstate = 0;
                        }
                        else if (d > a[i + 1]){
                            nstate = 2;
                        }
                    }
                    (dp[i + 1][b + d][nstate] += cur) %= mod;
                }
            }
        }
    }
    cost[1] = 1;
    for (int i = 2; i < maxN; i++){
        cost[i] = cost[__builtin_popcount(i)] + 1;
        // cout << i << " " << cost[i] << endl;
    }

    int res = 0;
    
    for (int i = 1; i <= n; i++){
        for (int b = 1; b <= i; b++){
            if (cost[b] == k){
                // cout << i << " " << b << ":" << endl; 
                // cout << "*" << endl;
                // cout << dp[i][b][0] << endl;
                // cout << dp[i][b][1] << endl;
                
                res += dp[i][b][0];
                res += dp[i][b][1];
                if (i != n){
                    // cout << dp[i][b][2] << endl;
                    res += dp[i][b][2];
                }
                res %= mod;
            }
        }
    }

    if (k == 0){
        res += 1;
    }

    if (k == 1 and n == 1 and a[1] == 1){
        res--;
    }

    cout << res << endl;

    return 0;
}

/*
111111011
*2 2
11
*3 2
101
110
*3 3
111
*4 2
1001
1010
1100
4 3
1100


*/
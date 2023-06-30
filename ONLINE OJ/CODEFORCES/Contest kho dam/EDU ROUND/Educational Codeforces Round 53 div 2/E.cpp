/*
8:50 23/6/2023
*/
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;

ii dp[20][1 << 11][4];
int a[100];

int cal(string s, int k){
    int k0 = k;
    k = 10;
    int n = s.length();
    for (int i = 1; i <= n; i++){
        for (int mask = 0; mask < (1 << k); mask++){
            dp[i][mask][0] = dp[i][mask][1] = dp[i][mask][2] = {0,0};
        }
    }
    
    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - '0';
    }

    for (int i = 1; i <= 9; i++){
        int state = 0;
        if (i == a[1]){
            state = 1;
        }
        else if (i > a[1]){
            state = 2;
        }
        dp[1][1 << i][state].fi++;
        dp[1][1 << i][state].se += i;
    }

    for (int i = 1; i <= n; i++){
        for (int mask = 1; mask < (1 << k); mask++){
            for (int state = 0; state <= 2; state++){
                ii cur = dp[i][mask][state];
                if (cur.fi == 0 or __builtin_popcount(mask) > k0){
                    continue;
                }
                // cout << i << " " << bitset<10>(mask) << " " << state << ": " << cur.fi << " " << cur.se << endl;
                for (int dig = 0; dig <= 9; dig++){
                    int nMask = mask | (1 << dig);
                    int nState = state;
                    if (nState == 1){
                        if (dig < a[i + 1]){
                            nState = 0;
                        }
                        else if (dig == a[i + 1]){
                            nState = 1;
                        }
                        else{
                            nState = 2;
                        }
                    }
                    (dp[i + 1][nMask][nState].fi += cur.fi) %= mod;
                    (dp[i + 1][nMask][nState].se += cur.se * 10 + dig * cur.fi) %= mod;
                    ii t = dp[i + 1][nMask][nState];
                    // cout << " => " << i + 1 << " " << bitset<10>(nMask) << " " << nState << ": " << t.fi << " " << t.se << endl;
                }
            }
        }
    }
    
    ii res = {0,0};

    for (int i = 1; i <= n; i++){
        for (int mask = 1; mask < (1 << k); mask++){
            if (__builtin_popcount(mask) <= k0){
                // if (dp[i][mask][0].fi){
                //     cout << i << " " << bitset<10>(mask) << " 0: " << dp[i][mask][0].fi << " " << dp[i][mask][0].se << endl;
                // }
                // if (dp[i][mask][1].fi){
                //     cout << i << " " << bitset<10>(mask) << " 1: " << dp[i][mask][1].fi << " " << dp[i][mask][1].se << endl;
                // }
                res.fi += dp[i][mask][0].fi;
                res.se += dp[i][mask][0].se;
                res.fi += dp[i][mask][1].fi;
                res.se += dp[i][mask][1].se;
                if (i != n){
                    // if (dp[i][mask][2].fi){
                    //     cout << i << " " << bitset<10>(mask) << " 2: " << dp[i][mask][2].fi << " " << dp[i][mask][2].se << endl;
                    // }
                    res.fi += dp[i][mask][2].fi;
                    res.se += dp[i][mask][2].se;
                }
                res.fi %= mod;
                res.se %= mod;
            }
        }
    }
    // cout << res.fi << ' ' << res.se << endl;
    return res.se;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r;
    int k;
    cin >> l >> r >> k;
    // cout << cal(to_string(r),k) << endl;
    cout << (cal(to_string(r),k) - cal(to_string(l - 1),k) + mod) % mod << endl;
    return 0;
}

/*
1

*/
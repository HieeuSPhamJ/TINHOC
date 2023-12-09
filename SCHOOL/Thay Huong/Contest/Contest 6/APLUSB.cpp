#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 10010;
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN][10][10][2][2];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("APLUSB.inp", "r")) {
        freopen("APLUSB.inp", "r", stdin);
        freopen("APLUSB.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if (s[0] == '1'){
        cout << 0 << endl;
        return 0;
    }
    int n = s.length();

    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - '0';
    }

    for (int i = 1; i < a[1]; i++){
        dp[1][i][a[1] - i][0][0] += 1;
        if (a[1] - i - 1 >= 1){
            dp[1][i][a[1] - i - 1][0][1] += 1;
        }
    }

    for (int i = 1; i < n; i++){
    for (int d1 = 0; d1 <= 9; d1++){
    for (int d2 = 0; d2 <= 9; d2++){
    for (int laRem = 0; laRem <= 1; laRem++){
    for (int rem = 0; rem <= 1; rem++){
        int cur = dp[i][d1][d2][laRem][rem];
        if (cur){
            for (int nd = 0; nd <= 9; nd++){
                int d = 10 * rem + a[i + 1];
                if (nd != d1){
                    if (0 <= d - nd and d - nd <= 9 and d - nd != d2){
                        (dp[i + 1][nd][d - nd][rem][0] += cur) %= mod;
                    }
                    if (0 <= d - nd - 1 and d - nd - 1 <= 9 and d - nd - 1 != d2){
                        (dp[i + 1][nd][d - nd - 1][rem][1] += cur) %= mod;
                    }
                }
            }
        }
    }}}}}

    int res = 0;
    for (int i = 0; i <= 9; i++){
        if (a[n] - i >= 0){
            (res += dp[n][i][a[n] - i][0][0]) %= mod;
        }
        if (a[n] + 10 - i <= 9){
            (res += dp[n][i][a[n] + 10 - i][1][0]) %= mod;
        }
    }

    cout << res << endl;

    return 0;
}

/*
32
12 20
20 12

13 19
14 18
15 17
16 16
17 15
18 14
19 13
*/
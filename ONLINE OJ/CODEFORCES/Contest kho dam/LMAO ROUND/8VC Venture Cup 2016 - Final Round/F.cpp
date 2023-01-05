#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int a[210];
int dp[2][100 * 500][201];

bool cmp(int x, int y){
    return x > y;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, val;
    cin >> n >> val;
    int maxVal = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxVal += a[i];
    }


    sort(a + 1, a + 1 + n, cmp);

    dp[1][a[1]][1] = 1;
    dp[1][0][0] = 1;

    for (int iii = 1; iii < n; iii++){
        bool i = iii % 2;
        bool li = (iii + 1) % 2;
        for (int val = 0; val <= maxVal; val++){
            for (int open = 0; open <= n; open++){
                dp[li][val][open] = 0;
            }
        }
        for (int val = 0; val <= maxVal; val++){
            for (int open = 0; open <= n; open++){
                int now = dp[i][val][open];
                if (now == 0){
                    continue;
                }
                // cout << "============" << endl;
                // cout << i << " " << val << " " << open << " : " << now << endl;
                (dp[li][val][open] += now) %= mod;
                (dp[li][val][open] += now * open) %= mod;
                // cout << "op and cls: " << li << " " << val << " " << open << " | " << dp[li][val][open] << endl;
                (dp[li][val + a[iii + 1]][open + 1] += now) %= mod;
                // cout << "open: " << li << " " << val + a[li] << " " << open + 1 << " | " << dp[li][val + a[li]][open + 1] << endl;
                if (val - a[iii + 1] >= 0){
                    (dp[li][val - a[iii + 1]][open - 1] += now * open) %= mod;
                    // cout << "cls: " << li << " " << val - a[li] << " " << open - 1 << " | " << dp[li][val - a[li]][open - 1] << endl;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= val; i++){
        (res += dp[n % 2][i][0]) %= mod;
    }

    cout << res;


    return 0;
}
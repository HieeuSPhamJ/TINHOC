#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[300][300];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        int x = (c == '1');
        dp[i][i] = x;
        for (int j = 1; j < i; j++){
            dp[j][i] = !(dp[j][i - 1] & x);
            // cout << j << " " << i << " " << dp[j][i] << endl;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            if (dp[j][i]){
                cout << j << ' ' << i << endl;
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 4 * 1e5 + 10;

string s;
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        char c;
        cin >> n >> c;
        cin >> s;
        s = '*' + s + s;

        int ans = 0;
        dp[2 * n] = 2 * n;

        for (int i = 2 * n - 1; i >= 1; i--){
            if (s[i] == 'g'){
                dp[i] = i;
                continue;
            }
            dp[i] = dp[i + 1];
            
        }

        for (int i = 1; i <= n; i++){
            if (s[i] == c){
                ans = max(ans, dp[i] - i);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
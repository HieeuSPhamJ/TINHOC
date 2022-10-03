#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
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
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if (i - a[i] >= 0){
                dp[i] = max(dp[i], dp[i - a[i]] + 1);
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}
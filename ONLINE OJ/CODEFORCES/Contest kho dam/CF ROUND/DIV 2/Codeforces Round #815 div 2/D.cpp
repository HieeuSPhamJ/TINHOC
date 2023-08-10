#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 * 3 + 10;

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
        for (int i = 0; i < n; i++){
            cin >> a[i];
            dp[i] = 1;
        }

        int ans = 0;

        for (int i = 1; i < n; i++){
            for (int j = i - 1; j >= (i - (1 << 8)); j--){
                if (j < 0){
                    break;
                }
                if ((a[i] xor j) > (a[j] xor i)){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN] = {0};
int dp[maxN] = {0};

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--){
        int n;
        cin >> n;
        int maxA = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            a[inp]++;
            maxA = max(maxA, inp);
        }

        dp[0] = 0;
        dp[1] = 1 * a[1];
        dp[2] = 2 * a[2];

        int ans = max(dp[1], dp[2]);

        for (int i = 3; i <= maxA; i++){
            dp[i] = dp[i - 2]+ a[i] * i;
            // cout << dp[i] << ' ';
            ans = max(ans, dp[i]);
        }
        cout << ans;
    }

    return 0;
}



#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

int dp[maxN];

main(){
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        memset(dp, 0, sizeof(dp));
        for (int i = 1;  i <= n; i++){
            cin >> a[i];
            dp[i] = dp[i - 1] + a[i];
        }


        if (k <= n){
            int ans = 0;
            for (int i = k; i <= n; i++){
                ans = max(ans, dp[i] - dp[i - k]);
            }
            int temp = 0;
            ans += (k * (k + 1)) / 2 - k;
            cout << ans;
        }
        else{
            int ans = dp[n];
            cout << ans << ' ';
            int temp  = 0;
            for (int i = 1; i < n; i++){
                temp += i;
            }
            int k = k - n;
            int t = k / n;
            int r = k % n;

            cout << t << ' ' << temp << ' ';

            ans += t * temp;
            // cout << ans << ' ';

            ans += (r * (r + 1)) / 2 - r;

            cout << ans;
        }


        cout << endl;
    }
    

    return 0;
}

/*
101
11
*/
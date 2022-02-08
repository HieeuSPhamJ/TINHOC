#include<bits/stdc++.h>
using namespace std;

const int maxN = 6 * 1e3 + 10;

int dp[maxN];
int a[maxN];

int main(){
    memset(dp, 0, sizeof(dp));
    int n, l;
    cin >> n >> l;
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        a[i] = a[i - 1] + inp;
        // cout << a[i] << ' ';
    }
    // cout << endl;
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int minL = l;
        // cout << "#" << i << endl;
        for (int e = 1; e <= i; e++){
            // cout << minL << endl;

            if (l - (a[i] - a[e - 1]) >= 0){
                minL = min(minL, max(dp[e - 1], l - (a[i] - a[e - 1])));
            }
        }
        dp[i] = minL;
        // for (int x = 1; x <= n; x++){
        //     cout << dp[x] << ' ';
        // }
        // cout << endl;
    }
    cout << dp[n];

    return 0;
}
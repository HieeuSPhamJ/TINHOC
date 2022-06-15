#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxMask = 1 << 17;

int dp[20][maxMask];
int a[20];

main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        dp[i][1 << i] = 1;
    }
    
    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if ((mask & (1 << i)) == (1 << i)){
                for (int j = 0; j < n; j++){
                    if (((mask & (1 << j)) == (1 << j)) and (abs(a[i] - a[j]) > k)){        
                        int lastMask = (mask & (~ (1 << i)));
                        dp[i][mask] += dp[j][lastMask];
                    }
                    
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += dp[i][(1 << n) - 1];
        // cout << dp[i][(1 << n) - 1] << endl;
    }

    cout << ans;

    return 0;
}
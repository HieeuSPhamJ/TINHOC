#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int dp[20][(1 << 17)];
int a[20];

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        dp[i][(1 << i)] = 1;
    }
    
    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (getBit(mask, i) == 0){
                continue;
            }
            for (int j = 0; j < n; j++){
                    if ((getBit(mask,j)) and (abs(a[i] - a[j]) > k)){        
                        int preMask = (mask & (~ (1 << i)));
                        dp[i][mask] += dp[j][preMask];
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

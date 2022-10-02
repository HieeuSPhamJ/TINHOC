#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[1 << 11];

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        int mask = 0;
        while(inp){
            mask = onBit(mask, inp % 10);
            inp /= 10;
        }
        dp[mask]++;
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << 10); mask++){
        if (dp[mask] == 0){
            continue;
        }
        for (int anoMask = 1; anoMask < (1 << 10); anoMask++){
            if (!dp[anoMask]){
                continue;
            }
            if ((mask & anoMask) == 0){
                ans += dp[mask] * dp[anoMask];
            }
        }   
    }
    ans /= 2;
    cout << (n * (n - 1)) / 2 - ans;

    return 0;
}

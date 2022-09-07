#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxMask = (1 << 20) - 1;
int dp[(1 << 21)];

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
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        map <char, bool> checkMap;
        int mask = 0;
        for (int j = i; j < n; j++){
            if (checkMap[s[j]] == 1){
                break;
            }
            checkMap[s[j]] = 1;
            mask = mask | (1 << (s[j] - 'a'));
            dp[mask] = max(dp[mask], abs(i - j) + 1);
        }
    }

    for (int mask = 0; mask < maxMask; mask++){
        // for(int subMask = mask; subMask; subMask = (subMask - 1) & mask){
            // dp[mask] = max(dp[mask], dp[subMask]);
        // }
        for(int i = 0; i < 20; i++){
            if(getBit(mask, i) == 1){
                dp[mask]=max(dp[mask],dp[offBit(mask, i)]);
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < maxMask; mask++){
        int antiMask = mask xor maxMask;
        ans = max(ans, dp[mask] + dp[antiMask]);
    }
    cout << ans;
    return 0;
}
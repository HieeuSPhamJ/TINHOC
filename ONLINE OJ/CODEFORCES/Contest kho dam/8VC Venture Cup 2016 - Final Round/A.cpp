#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[50][2];

bool getBit(int mask, int i){
    return (mask & (1ll << i));
}

int onBit(int mask, int i){
    return mask | (1ll << i);
}

int offBit(int mask, int i){
    return (mask xor (1ll << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1ll);
        mask >>= 1ll;
    }
    return count;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s,x;
    cin >> s >> x;
    int n = max(log2(s), log2(x));
    for (int i = 0; i <= 1ll; i++){
        for (int j = 0; j <= 1ll; j++){
            int SUM = i + j;
            int XOR = i xor j;
            if (getBit(SUM,0) == getBit(s,0) and getBit(XOR, 0) == getBit(x,0)){
                dp[0][getBit(SUM,1ll)]++;
            }
        }   
    }
    for (int i = 0; i < n; i++){
        for (int rem = 0; rem <= 1ll; rem++){
            int now = dp[i][rem];
            if (now == 0){
                continue;
            }
            for (int a = 0; a <= 1ll; a++){
                for (int b = 0; b <= 1ll; b++){
                    int SUM = a + b + rem;
                    int XOR = a xor b;
                    if (getBit(SUM,0) == getBit(s,i + 1ll) and getBit(XOR, 0) == getBit(x,i + 1ll)){
                        dp[i + 1ll][getBit(SUM,1ll)] += now;
                    }
                }   
            }
        }
    }
    // for (int i = n; i >= 0; i--){
    //     cout << dp[i][0] << " ";
    // }
    // cout << endl;
    // for (int i = n; i >= 0; i--){
    //     cout << dp[i][1ll] << " ";
    // }
    // cout << endl;
    if (x == s){
        cout << dp[n][0] - 2 << endl;
        return 0;
    }
    cout << dp[n][0];
    return 0;
}
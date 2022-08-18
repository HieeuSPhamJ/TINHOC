#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


const int mod = 1e9 + 7;

int countBit[(1 << 11)];
int countPairMask[(1 << 10) + 5][(1 << 10) + 5];
int dp[102][(1 << 10) + 5][21][21];

bool getBit(int mask, int i){
    return mask & (1 << i);
}

int setBit(int mask, int i){
    return mask | (1 << i);
}

void init(){
    for (int mask = 0; mask < (1 << 10); mask++){
        int count = 0;
        for (int i = 0; i <= 10; i++){
            if (getBit(mask,i) == 1){
                count++;
            }
        }
        countBit[mask] = count;
        for (int preMask = 0; preMask < (1 << 10); preMask++){
            int countPair = 0;
            // cout << mask << " | " << preMask << " ";
            for (int i = 0; i < 10; i++){
                if (getBit(mask,i) == 1 and getBit(mask, i + 1) == 1){
                    countPair++;
                }
            }
            for (int i = 0; i <= 10; i++){
                if (getBit(mask,i) == 1 and getBit(preMask, i) == 1){
                    countPair++;
                }
            }
            // cout << countPair << endl;
            countPairMask[mask][preMask] = countPair;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    init();
    while(test--){
        int n, m, c, k;
        cin >> n >> m >> c >> k;
        if (n > m){
            swap(n, m);
        }

        memset(dp, 0, sizeof(dp));

        int maxMask = (1 << n);

        for (int mask = 0; mask < maxMask; mask++){
            if (countBit[mask] > c){
                continue;
            }      
            int countPair = 0;
            dp[1][mask][countBit[mask]][countPairMask[mask][0]] = 1;
            // cout << mask << ' ' << countPairMask[mask][0] << endl;
        }

        for (int i = 1; i < m; i++){
            for (int mask = 0; mask < maxMask; mask++){
                for (int cow = countBit[mask]; cow <= c; cow++){
                    for (int countPair = countPairMask[mask][0]; countPair <= k; countPair++){
                        int now = dp[i][mask][cow][countPair];
                        if (now == 0){
                            continue;
                        }
                        // cout << "#" << i << " " << mask << " " << cow << " " << countPair << ": " << endl;
                        for (int nextMask = 0; nextMask < maxMask; nextMask++){
                            int nextCow = cow + countBit[nextMask];
                            int nextPair = countPair + countPairMask[nextMask][mask];
                            if (nextCow > c){
                                continue;
                            }
                            if (nextPair > k){
                                continue;
                            }
                            (dp[i + 1][nextMask][nextCow][nextPair] += now) %= mod;

                            // cout << i + 1 << " " << nextMask << " " << nextCow << " " << nextPair << endl;
                        }
                        // cout << endl;
                        
                    }
                }
            }
        }

        int ans = 0;

        for (int mask = 0; mask < maxMask; mask++){
            for (int countPair = 0; countPair <= k; countPair++){
                ans += dp[m][mask][c][countPair];
            }
        }

        cout << ans % mod << endl;
    }
    return 0;
}
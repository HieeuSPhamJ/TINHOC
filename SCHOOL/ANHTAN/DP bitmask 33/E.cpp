#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int n;
int a[20][20];
int dp[(1 << 16)];
int cost[(1 << 16)];

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

void init(){
    for (int mask = 0; mask < (1 << n); mask++){
        vector <int> listBits;
        // cout << mask << ": ";
        for (int i = 0; i <= log2(mask); i++){
            if (getBit(mask, i) == 1){
                listBits.push_back(i);
                // cout << i << ' ';
            }
        }
        // cout << endl;
        for (auto i: listBits){
            for (auto j: listBits){
                if (i < j){
                    cost[mask] += a[i][j];
                }
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    init();

    for (int mask = 0; mask < (1 << n); mask++){
        for(int subMask = mask; subMask; subMask = (subMask - 1) & mask){
            int preMask = mask xor subMask;
            dp[mask] = max(dp[mask], dp[preMask] + cost[subMask]);
        }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}

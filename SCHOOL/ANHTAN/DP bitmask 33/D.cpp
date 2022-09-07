#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int dp[22][(1 << 21)];
int a[33][33];
int n;
vector <int> listMask[22];

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
    for (int j = 0; j < n; j++){
        if (a[0][j] == 1){
            dp[0][(1 << j)]++;
        }
    } 
    for (int mask = 0; mask < (1 << n); mask++){
        listMask[countBits(mask)].push_back(mask);
    }
}

signed main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
   
    init();


    // cout << countBits(3) << endl;

    for (int i = 1; i < n; i++){
        for (auto mask: listMask[i + 1]){
            for (int j = 0; j < n; j++){
                if (a[i][j] == 1 and getBit(mask, j) == 1){
                    int preMask = offBit(mask, j);
                    (dp[i][mask] += dp[i - 1][preMask]) %= mod;
                }
            } 
        }
    }

    cout << dp[n - 1][(1 << n) - 1];

    return 0;
}

#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

double a[20][20];
double dp[18][(1 << 19)];

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
    return __builtin_popcount(mask);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }

    vector <int> masks[20];

    for (int i = 0; i < (1 << n); i++){
        masks[countBits(i)].push_back(i);
    } 
    for (int i = 0; i < n; i++){
        dp[i][onBit(0,i)] = 1;
    }
    for (int num = 1; num < n; num++){
        for (auto mask: masks[num]){
            for (int i = 0; i < n; i++){
                if (!getBit(mask,i)){   
                    continue;
                }
                double now = dp[i][mask];
                cout << i << ": " << bitset<3>(mask) << " " << now << endl;
                for (int j = 0; j < n; j++){
                    if (i == j){
                        continue;
                    }
                    if (getBit(mask, j) == 1){
                        continue;
                    }
                    cout << i << " " << j << endl;
                    dp[i][onBit(mask, j)] = max(dp[i][onBit(mask, j)], now * a[i][j]);
                    dp[j][onBit(mask, j)] = max(dp[j][onBit(mask, j)], now * a[j][i]);    
                    cout << i << " " << bitset<3>(onBit(mask, j)) << " " << dp[i][onBit(mask, j)] << endl;
                    cout << j << " " << bitset<3>(onBit(mask, j)) << " " << dp[j][onBit(mask, j)] << endl;
                    
                }
            }
        }
    }
    cout << dp[0][(1 << n) - 1];
    return 0;
}
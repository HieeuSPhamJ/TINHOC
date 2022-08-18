#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 22;

int n, m;
const int maxMask (1 << maxN);
int a[maxN][maxN];
vector <int> listMask[maxN];
int dp[maxMask];

void backtracking(int id, int mask, int count){
    if (id == n){
        listMask[count].push_back(mask);
        return;
    }
    backtracking(id + 1, mask, count);
    backtracking(id + 1, (mask | (1 << id)), count + 1);
}

bool getBit(int mask, int i){
    return mask & (1 << i);
}

int setBit(int mask, int i){
    return mask | (1 << i);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    backtracking(0,0,0);

    // for (int i = 0; i <= n; i++){
    //     cout << i << ": ";
    //     for (auto mask: listMask[i]){
    //         cout << mask << ' ';
    //     }
    //     cout << endl;
    // }

    for (int count = n - 1; count >= m; count--){
        for (auto mask: listMask[count]){
            // cout << -1;
            int minDP = 1e18;
            for (int i = 0; i < n; i++){
                if (getBit(mask, i) == 1){
                    continue;
                }
                int minCost = 1e18;
                
                for (int j = 0; j < n; j++){
                    if (getBit(mask, j) == 0){
                        continue;
                    }
                    minCost = min(minCost, a[i][j]);
                    // cout << a[i][j] << ' ' << i << " " << j << endl;
                }
                // cout << endl;

                int preMask = setBit(mask, i);
                // cout << mask << "<--" << preMask << " " << minCost << endl;
                minDP = min(minDP, dp[preMask] + minCost);
            }
            dp[mask] = minDP;
        }
    }

    int ans = 1e8;

    for (auto mask: listMask[m]){
        ans = min(ans, dp[mask]);
        // cout << mask << ' ';
    }
    // cout << endl;
    
    cout << ans;
    return 0;
}


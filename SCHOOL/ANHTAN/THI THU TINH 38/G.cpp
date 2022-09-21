#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 19;

int a[maxN];
int dp[maxN][(1 << maxN)];
int c[maxN][maxN];
vector <int> listMask[maxN];


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
    int n, m, k;
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[i][(1 << i)] = a[i];
        ans = max(ans, dp[i][(1 << i)]);
    }

    for (int i = 1; i <= k; i++){
        int x, y, w;
        cin >> x >> y >> w;
        c[y - 1][x - 1] = max(c[y - 1][x - 1], w);
    }

    for (int i = 0; i < (1 << n); i++){
        listMask[countBits(i)].push_back(i);
    }


    for (int num = 2; num <= m; num++){
        for (auto mask: listMask[num]){
            for (int i = 0; i < n; i++){
                if (getBit(mask,i) == 0){
                    continue;
                }
                int preMask = offBit(mask, i);
                for (int j = 0; j < n; j++){
                    if (getBit(preMask,j) == 0){
                        continue;
                    }
                    dp[i][mask] = max(dp[i][mask], dp[j][preMask] + c[i][j] + a[i]);
                    ans = max(ans, dp[i][mask]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
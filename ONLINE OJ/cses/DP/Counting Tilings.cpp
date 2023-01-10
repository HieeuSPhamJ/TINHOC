#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e3;
const int maxMask = (1 << 10) + 1;

int n, m;
int dp[maxN][maxMask][maxMask];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        for (int mask = 0; mask <= (1 << m) - 1; mask++){
            for (int preMask = 0; preMask <= (1 << m) - 1; preMask++){
                
            }
        }
    }
    return 0;
}


/*
    dp[i][j] = dp

*/

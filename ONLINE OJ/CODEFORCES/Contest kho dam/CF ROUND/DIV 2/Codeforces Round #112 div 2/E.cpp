#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


const int maxBit = 22;
const int maxN = 1 << maxBit;

int a[maxN];
int dp[maxN];
int ndp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(ndp, -1, sizeof(ndp));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[a[i]] = a[i];
        // cout << bitset<maxBit>(a[i]) << " " << dp[a[i]][0] << endl;
    }

    for (int i = 0; i <= maxBit; i++){
        for (int mask = 1; mask < maxN; mask++){
            ndp[mask] = dp[mask];
            if (mask & (1 << i)){
                ndp[mask] = max(ndp[mask], dp[mask xor (1 << i)]);
            }
            // cout << mask << " " << i << ": " << dp[mask][i] << endl;
        }
        swap(dp,ndp);
    }

    // cout << dp[90][0] << endl;

    for (int i = 1; i <= n; i++){
        int mask = (1 << (maxBit)) - 1;
        mask = mask xor a[i];
        cout << dp[mask] << " ";
    }   

    return 0;
}

/*
0011011 
1011010
*/
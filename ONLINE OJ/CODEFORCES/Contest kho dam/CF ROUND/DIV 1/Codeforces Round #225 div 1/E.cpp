#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxBit = 24;
const int maxN = 1 << maxBit;

int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        char a,b,c;
        cin >> a >> b >> c;
        int mask = (1 << (a - 'a')) | (1 << (b - 'a')) | (1 << (c - 'a'));
        dp[mask]++;
        // cout << bitset<maxBit>(mask) << endl;
    }
    // cout << "======" << endl;
    for (int i = 0; i < maxBit; i++){
        for (int mask = 0; mask < maxN; mask++){
            if (mask & (1 << i)){
                dp[mask] += dp[mask xor (1 << i)];
            }
        }
    }

    int res = 0;
    for (int i = 1; i < maxN; i++){
        int mask = (1 << maxBit) - 1;
        mask = mask xor i;
        res = res xor ((n - dp[mask]) * (n - d[mask]) % 2) * mask;
        cout << bitset<maxBit>(i) << endl;
        // cout << bitset<maxBit>(mask) << " ";
        cout << n - dp[mask] << endl;
    }
    cout << res << endl;
    return 0;
}
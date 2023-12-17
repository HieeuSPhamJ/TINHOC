#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e9 + 7;

int dp[20][1 << 20];
int a[20][20];

void add(int &a, int b){
    (a += b) %= mod;
}

vector <int> adj[1 << 20];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }    
    for (int i = 0; i < n; i++){
        dp[0][1 << i] = a[0][i];
    }

    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if ((mask & (1 << i)) == 0 and a[__builtin_popcount(mask)][i]){
                adj[mask].push_back(i);
            }
        }
    }

    for (int i = 0; i < n - 1; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            int cur = dp[i][mask];
            if (cur == 0){
                continue;
            }
            // cout << i << " " << bitset<3>(mask) << ": " << cur << endl;
            for (auto x: adj[mask]){
                // cout << " " << i + 1 << " " << bitset<3>(mask | (1 << x)) << endl;
                add(dp[i + 1][mask | (1 << x)], cur);
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] << endl;
    return 0;
}
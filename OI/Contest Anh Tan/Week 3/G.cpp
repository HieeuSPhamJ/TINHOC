#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e9 + 7;

vector <int> adj[60];
int dp[60][1 << 16];

void add(int &a, int b){
    (a += b) %= mod;
}

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            int cur = dp[i - 1][mask];
            if (cur == 0){
                continue;
            }
            add(dp[i][mask], cur);
            for (auto x: adj[i]){
                if (mask & (1 << x)){
                    continue;
                }
                add(dp[i][mask | (1 << x)], cur);
            }
        }
    }

    cout << dp[m][(1 << n) - 1];
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

int num[(1 << 20)];
int dp[(1 << 20)];
int p[(1 << 20)];

signed main(){
    freopen("Tohop.INP", "r", stdin);
    freopen("Tohop.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;++i){
        int k;
        cin >> k;
        int mask = 0;
        while(k--){
            int x;
            cin >> x;
            x--;
            mask = mask | (1 << x);
        }
        num[mask]++;
    }
    
    for (int i = 0; i < (1 << m); i++){
        dp[i] = num[i];
    }
    p[0] = 1;
    for (int i = 1; i < (1 << 20); i++){
        p[i] = p[i - 1] + p[i - 1];
        p[i] %= mod;
    }
    for (int i = 0; i < m; i++){
        for (int mask = 0; mask < (1 << m); mask++){
            if (mask & (1 << i)){
                (dp[mask] += dp[mask xor (1 << i)]) %= mod;
            }
        }
    }
    int res = p[n];
    for(int mask = 1; mask < (1 << m); mask++){
        int antimask = mask ^ ((1 << m) - 1);
        if(__builtin_popcount(mask) % 2){
            res -= p[dp[antimask]];
        }
        else{
            res += p[dp[antimask]];
        }
        (res += mod) %= mod;
    }
    
    cout << res << endl;
    
    return 0;
}
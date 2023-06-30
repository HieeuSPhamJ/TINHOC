#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxBit = 20;
const int maxN = 1 << maxBit;
const int mod = 1e9 + 7;

int a[maxN];
int f[maxN];
int dp[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        f[x]++;
    }

    for (int i = 0; i <= maxBit; i++){
        for (int mask = 0; mask < maxN; mask++){
            if (mask & (1 << i)){
                f[mask] += f[mask xor (1 << i)];
            }
        }
    }

    for (int mask = 0; mask < maxN; mask++){
        // cout << bitset<maxBit>(mask) << " " << f[mask] << " " << (1 << f[mask]) << endl;
        f[mask] = fastpow(2, f[mask]);
    }  

    for (int mask = 0; mask < maxN; mask++){
        dp[mask] = f[mask];
    }

    
    for (int i = 0; i <= maxBit; i++){
        for (int mask = 0; mask < maxN; mask++){
            if (mask & (1 << i)){
                // cout << bitset<maxBit>(mask) << " " << bitset<maxBit>(mask xor (1 << i)) << endl;
                dp[mask] = subtr(dp[mask], dp[mask xor (1 << i)]);
            }
        }
    } 

    int res = 0;

    for (int mask = 0; mask < maxN; mask++){
        res = add(res, mul(fastpow(mask,3), dp[mask]));
        // cout << bitset<maxBit>(mask) << " " << dp[mask] << endl;
    }  

    cout << res << endl;

    return 0;
}

/*
3
1 2
1 3
2 3
1 2 3
*/
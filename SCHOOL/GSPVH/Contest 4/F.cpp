#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e4 + 7;

int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int t = fastpow(n,a / 2);
    t *= t;
    if (a % 2){
        return t * n;
    }
    return t;
}

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (a * b) % mod;
}
int divi(int a, int b){
    return a * fastpow(b,mod - 2);
}
int subtr(int a, int b){
    return (a - b + mod) % mod;
}

ii a[maxN];
int dp[maxN][22];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int total = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        total = mul(total, add(a[i].fi, a[i].se));
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < k; j++){
            dp[i][j] = add(mul(dp[i - 1][j - 1], a[i].fi), mul(dp[i - 1][j], a[i].se));
        }
    }
    int test;
    cin >> test;
    while(test--){
        int id, x, y;
        cin >> id >> x >> y;
        total = divi(total,add(a[id].fi, a[id].se));
        total = mul(total, add(x, y));

        for (int i = 0; i < k; i++){
            dp[n - 1][i] = divi(dp[n][i],);
        }

        int res = total;
        for (int i = 0; i < k; i++){
            res = subtr(res, dp[n][i]);
        }
    }
    return 0;
}
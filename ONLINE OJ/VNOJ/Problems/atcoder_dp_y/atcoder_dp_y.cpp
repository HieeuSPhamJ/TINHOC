#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int fact[maxN];
int infact[maxN];

int add(int a, int b){
    return (a + b) % mod;
}

int subtr(int a, int b){
    return (a - b + mod) % mod;
}

int mul(int a, int b){
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    if (a == 0){
        return 1;
    }
    int t = fastpow(n, a / 2);
    if (a % 2){
        return mul(mul(t,t), n);
    }
    return mul(t,t);
}

int di(int a, int b){
    return a * fastpow(b, mod - 2);
}

int C(int n, int k){
    // cout << n << " " << k << endl;
    return mul(fact[n], mul(infact[n - k], infact[k]));
}

void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = di(1, fact[maxN - 1]);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], (i + 1));
    }
}

ii a[maxN];
int dp[maxN];

void print(ii a, char en = endl){
    cout << a.fi << " " << a.se << en;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n, m, k;
    cin >> n >> m >> k;
    int res = C((n - 1) + (m - 1), n - 1);
    for (int i = 1; i <= k; i++){
        cin >> a[i].fi >> a[i].se;
    }

    // cout << subtr(4, 3) << endl;
    
    k++;

    a[k] = {n,m};

    sort(a + 1, a + k + 1);


    for (int i = 1; i <= k; i++){
        dp[i] = C(a[i].fi - 1 + a[i].se - 1, a[i].fi - 1);
        // cout << "With " << i << ": "; print(a[i], ' ');
        // cout << dp[i] << endl;
        for (int j = 1; j <= k; j++){
            if (i != j and a[j].fi <= a[i].fi and a[j].se <= a[i].se){
                int x = a[i].fi - a[j].fi;
                int y = a[i].se - a[j].se;
                dp[i] = subtr(dp[i], mul(dp[j], C(x + y, x)));
                // print(a[j], ':');
                // cout << dp[j] << " " << C(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi) << endl;
            }
        }
        // cout << dp[i] << endl;
    }


    cout << dp[k] << endl;
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;
const int mod = 998244353;

int add(int a, int b){
    return (a + b) % mod;
}

int mul(int a, int b){
    return (a * b) % mod;
}

int sub(int a, int b){
   return (a - b + mod) % mod;
}

int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int t = fastpow(n,a / 2);
    t = mul(t,t);
    if (a % 2){
        return mul(t,n);
    }
    return t;
}

int divi(int a, int b){
    return mul(a, fastpow(b, mod - 2));
}

int cnt[maxN];
ii dp[maxN][maxN];
ii pre[maxN];
ii pren[maxN];

ii addii(ii a, ii b){
    return {(a.fi * b.se + b.fi * a.se) % mod, (a.se * b.se) % mod};
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
        cnt[x]++;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = {0,1};
        }
    }
    dp[0][0] = {1,1};
    pren[0] = {0,1};
    ii res = {0,1};
    for (int i = 0; i <= n; i++){
        pren[i + 1] = addii(pren[i], dp[0][i]);
        // cout << i + 1 << ": " << pren[i + 1].fi << " " << pren[i + 1].se << endl;
    }
    for (int i = 1; i <= n; i++){
        swap(pre,pren);
        pren[0] = {0,1};
        for (int j = 0; j <= n; j++){
            // for (int k = 0; k < j; k++){
            //     ii t = dp[i - 1][k];
            //     t.fi = mul(t.fi, cnt[j]);
            //     t.se = mul(t.se, n - i + 1);
            //     dp[i][j] = addii(dp[i][j], t);
            // }
            // cout << i << " " << pre[j].fi << " " << pre[j].se << endl;
            ii t = pre[j];
            t.fi = mul(t.fi, cnt[j]);
            t.se = mul(t.se, n - i + 1);
            dp[i][j] = t;
            ii cur = dp[i][j];
            // cout << i << " " << j << ": " << cur.fi << " " << cur.se << endl;
            if (cnt[j] >= 2 and cur.fi != 0){
                cur.fi = mul(cur.fi, cnt[j] - 1);
                cur.se = mul(cur.se, n - i);   
                res = addii(res,cur);
            }
            pren[j + 1] = addii(pren[j], dp[i][j]);
            // cout << i << " " << j + 1 << ": " << pre[i][j  + 1].fi << " " << pre[i][j + 1].se << endl;
        }
    }

    // cout << res.fi << " " << res.se << endl;
    cout << divi(res.fi,res.se);
    return 0;
}

/*
dp[i][j]
=> dp[i + 1][k] = dp[i][j] * cnt[k] / (n - i)

=> dp[i][j] = sum (dp[i - 1][k] * cnt[j] / (n - i + 1))
=> dp[i][j] = pre[i - 1][k] * cnt[j] / (n - i + 1);


2/8 * 1/7
1/8 * 1/7 * 1/6 * 2/5 * 1/4
1/8 * 1/7 * 2/6 * 1/5
1/8 * 1/7 * 2/6 * 1/5
1/8 * 1/7 * 2/6 * 1/5
1/8 * 2/7 * 1/6
1/8 * 2/7 * 1/6
1/8 * 2/7 * 1/6

1 3: 32 64
2 3: 288 1728
*/
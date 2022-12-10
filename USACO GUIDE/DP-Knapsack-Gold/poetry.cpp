#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 5010;
int fact[maxN];
int infact[maxN];

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
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = fastpow(fact[maxN - 1], mod - 2);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], i + 1);
    }
    
}
int C(int n, int k){
    return mul(fact[n], mul(infact[k], infact[n - k]));
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}


ii a[maxN];
int dp[maxN];
int cnt[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    dp[0] = 1;
    for (int sum = 0; sum <= k; sum++){
        for (int i = 1; i <= n; i++){
            if (sum +a[i].fi <= k){
                dp[sum + a[i].fi] = add(dp[sum + a[i].fi], dp[sum]);
            }
        }
    }

    // for (int i = 1; i <= k; i++){
    //     cout << dp[i] << " "; 
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        cnt[a[i].se] = add(cnt[a[i].se], dp[k - a[i].fi]);
    }

    vector <int> lists;

    for (int i = 1; i <= m; i++){
        char inp;
        cin >> inp;
        lists.push_back(inp - 'A');
    }

    sort(lists.begin(), lists.end());

    lists.push_back(-1);

    vector <int> cntline;

    for (int i = 1, count = 1; i <= m; i++){
        if (lists[i] != lists[i - 1]){
            cntline.push_back(count);
            count = 0;
        }
        count++;
    }

    int ans = 1;

    for (auto num: cntline){
        int tans = 0;
        for (int i = 1; i <= n; i++){
            tans = add(tans, fastpow(cnt[i], num));  
        }
        ans = mul(ans, tans);
    }

    // for (int i = 1; i <= n; i++){
    //     cout << cnt[i] << endl;
    // }

    cout << ans;


    return 0;
}

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

const int maxN = 3e5 + 10;

int n, k, p;
int dp[maxN];

void init(){
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++){
        dp[i] = 1 + dp[i - 1];
        if (i - p - 1 >= 0){
            dp[i] += dp[i - p - 1] - 1;
            // cout << i << " " << i - k - 1 << endl;
        }
    }
    // for (int i = 0; i <= n; i++){
    //     cout << i << ": " << dp[i] << endl;
    // }
}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> p;
    init();
    string s;
    cin >> s;
    int k0 = 1;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            k0 += dp[n - i - 1];
            // cout << i << " " << dp[n - i - 1] << endl;
        }
    }
    k += k0;
    // cout << "target: " << k << " " << k0 << endl;
    if (dp[n] < k){
        cout << -1 << endl;
        return 0;
    }
    for (int i = n, cnt = 1; i >= 1; i--){
        // cout << i << " " << cnt << " " << dp[i - 1] << endl;
        if (cnt + dp[i - 1] <= k){
            cout << 1;
            cnt += dp[i - 1];
        }
        else{
            cout << 0;
        }
        // cout << endl;
    }
    cout << endl;
    return 0;
}

/*
dp[i][state]
    dp[i - k][state]

*/
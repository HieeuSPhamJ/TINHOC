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

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

const int maxN = 1e6 + 10;

int dp[maxN];
int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int la = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        la = a[i];
        a[i] += a[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = -1;
    for (int i = 1; i <= n; i++){
        // cout << "With: " << a[i] << endl;
        for (int j = 0; j + a[i] <= k; j++){
            if (minimize(dp[j + a[i]], dp[j] + 1 + i)){
                // cout << j << " -> " << j + a[i] << ": " << dp[j + a[i]] << endl;
            }
        }
    }

    int res = dp[k];
    if (k - a[n] >= 0){
        int tres = 1e18;
        for (int i = 0; i <= k; i++){
            int t = k - (i + a[n]);
            if (t >= 0 and t % la == 0){
                minimize(tres, dp[i] + 1 + n + t / la);
            }
        }
        res = min(res, tres);
        
    }

    if (res > 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}


/*
2 + 1
2 + 1 + 2 + 2 + 2 + 2 + 2 + 2 + 2
*/
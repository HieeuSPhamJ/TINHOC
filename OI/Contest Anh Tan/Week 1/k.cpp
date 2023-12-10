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
int a[maxN];

void init(){
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++){
        dp[i] = 1 + dp[i - 1];
        if (i - p - 1 >= 0){
            dp[i] += dp[i - p - 1] - 1;
            // cout << i << " " << i - k - 1 << endl;
        }
        if (dp[i] >= 1e9){
            break;
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
    for (int i = 1; i <= n; i++){
        a[i] = (s[n - i] == '1');
    }
    int ok = 1;
    for (int i = n; i >= 1; i--){
        
    }

    return 0;
}

/*
dp[i][state]
    dp[i - k][state]

*/
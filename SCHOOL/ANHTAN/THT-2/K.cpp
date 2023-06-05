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
int dp[2000];
int pre[2000];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;   
        for (int sum = 1000; sum >= 0; sum--){
            (dp[sum + x] += dp[sum]) %= mod;
        }
    }

    for (int i = 1; i <= 1000; i++){
        (pre[i] = pre[i - 1] + dp[i]) %= mod;
    }

    int test;
    cin >> test;
    while(test--){
        int l, r;
        cin >> l >> r;
        cout << (pre[r] - pre[l - 1] + mod) % mod << endl;
    }

    return 0;
}
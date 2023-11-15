#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a[1 << 20];
int dp[1 << 20];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("mind.inp", "r")) {
        freopen("mind.inp", "r", stdin);
        freopen("mind.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << 20); i++){
        dp[i] = 1e18;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[a[i]] = 0;
    }

    for (int i = 1; i <= n; i++){
        
    }

    return 0;
}
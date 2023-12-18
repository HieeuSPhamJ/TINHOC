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

int a[510];
int dp[510][510];

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int r = 1; r <= n + 1; r++){
        for (int l = r - 2; l >= 0; l--){
            for (int i = l + 1; i < r; i++){
                maximize(dp[l][r], dp[l][i] + dp[i][r] + a[l] * a[i] * a[r]);
            }
        }
    }
    cout << dp[0][n + 1] << endl;
    return 0;
}
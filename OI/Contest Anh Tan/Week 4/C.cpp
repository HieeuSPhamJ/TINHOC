#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define ban 0
#define mua 1
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

int a[maxN];
int dp[110][2];

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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // cout << a[i] << endl;
    }
    for (int i = 0; i <= k; i++){
        dp[i][0] = dp[i][1] = -1e18;
    }
    /*
    1: mua
    0: ban
    */
   dp[0][ban] = 0;
//    cout << a[1] << endl;
   int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            maximize(dp[j][mua], dp[j][ban] - a[i]);
            if (j){
                maximize(dp[j][ban], dp[j - 1][mua] + a[i]);
            }
            maximize(res, dp[j][ban]);
        }
    }

    cout << res;

    return 0;
}

/*
7 1 5 3 6 4
-1 + 5 -3 + 6
*/
#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;

int a[maxN];
int dp[maxN][70];
int last[maxN][70];

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
    // freopen("262144.in", "r", stdin);
    // freopen("262144.out", "w", stdout);
    if (fopen("gameso.inp", "r")) {
        freopen("gameso.inp", "r", stdin);
        freopen("gameso.out", "w", stdout);
    }
    if (fopen("262144.in", "r")) {
        freopen("262144.in", "r", stdin);
        freopen("262144.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 60; j++){
            last[i][j] = i;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        last[i][a[i]] = i - 1;
    }
    dp[1][a[1]] = 1;
    last[1][a[1]] = 0;
    int res = a[1];
    for (int i = 2; i <= n; i++){
        // cout << "With: " << i << endl;
        dp[i][a[i]] = dp[i - 1][a[i]] + 1;
        last[i][a[i]] = last[i - 1][a[i]];
        // cout << " " << a[i] << ": " << dp[i][a[i]] << " " << last[i][a[i]] << endl;
        res = max(res, a[i]);

        for (int j = a[i] + 1, ok = 1; j <= 60; j++){
            int len = dp[i][j - 1];
            if (len % 2){
                ok = 0;
            }
            dp[i][j] = len / 2;
            if (ok){
                dp[i][j] += dp[last[i][j - 1]][j];
            }
            if (dp[i][j] and len / 2){
                res = max(res, j);
            }
            else{
                break;
            }
            if (ok){
                last[i][j] = min(last[i][j - 1], last[last[i][j - 1]][j]);   
            }
            else{
                last[i][j] = i;
            }
            // cout << " " << j << ": " << dp[i][j] << " " << last[i][j] << " " << ok << endl;
        }
    }
    cout << res << endl;
    return 0;
}

/*
4 3 2 1 1 
*/

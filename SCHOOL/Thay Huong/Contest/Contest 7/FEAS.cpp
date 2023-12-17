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

const int maxN = 2010;

int dp[maxN][maxN][2];
int a[maxN];

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
    if (fopen("FEAS.inp", "r")) {
        freopen("FEAS.inp", "r", stdin);
        freopen("FEAS.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (*min_element(a + 1, a + 1 + n) >= 0){
        int res = 0;
        for (int i = 1; i <= n; i++){
            res += a[i];
        }
        cout << res << endl;
        return 0;
    }
    if (k == 1){
        int res = 0;
        for (int i = 1, mi = 0, pre = 0; i <= n; i++){
            pre += a[i];
            maximize(res, pre - mi);
            minimize(mi, pre);
        }
        cout << res;
        return 0;
    }
    if (n > 2000){
        int res = 0;
        for (int i = 1; i <= n; i++){
            res += a[i];
        }
        cout << res - min(0ll, *min_element(a + 1, a + 1 + n)) << endl;
        return 0;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            maximize(dp[i][j][1], dp[i - 1][j][1] + a[i]);
            maximize(dp[i][j][1], dp[i - 1][j - 1][0] + a[i]);
            maximize(dp[i][j][0], dp[i - 1][j][0]);
            maximize(dp[i][j][0], dp[i - 1][j][1]); 
        }
    }

    cout << max(dp[n][k][0], dp[n][k][1]);
    return 0;
}
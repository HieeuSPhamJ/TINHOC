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

const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];
int dp[110][110];

int maximize(int &x, int y){
    if (x < y){
        x = y;
        return 1;
    }
    return 0;
}

int cal(int l, int r){
    if (l > r){
        return 0;
    }
    int &res = dp[l][r];
    if(res != -1){
        return res;
    }
    if (l == r){
        return res = b[l];
    }
    
    res = min(cal(l + 2, r), cal(l + 1, r - 1)) + b[l];
    maximize(res, min(cal(l, r - 2), cal(l + 1, r - 1)) + b[r]);
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("IVAN.inp", "r")) {
        freopen("IVAN.inp", "r", stdin);
        freopen("IVAN.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= 2;
        sum += a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            b[j - i] = a[j];
        }
        for (int j = 1; j < i; j++){
            b[n - i + j] = a[j];
        }
        // for (int j = 1; j <= n; j++){
        //     cout << b[j] << " ";
        // }
        // cout << endl;
		memset(dp, -1, sizeof(dp));
        res += ((sum - cal(1,n - 1)) > (sum / 2));
    }

    cout << res << endl;

    return 0;
}
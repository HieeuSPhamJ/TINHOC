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

int dp[310][310];
int a[310];

int cal(int l, int r){
    int &res = dp[l][r];
    if (res != -1){
        return res;
    }

    if (l >= r){
        return res = 0;
    }
    if (r - l == 1){
        if (abs(a[l] - a[r]) <= 1){
            return res = 2;
        }
        else{
            return res = 0;
        }
    }

    if (abs(a[l] - a[r]) <= 1 and cal(l + 1, r - 1) == r - l - 1){
        res = r - l + 1;
        // cout << l << " " << r << " " << res << endl;
    }   

    for (int i = l; i < r; i++){
        res = max(res, cal(l, i) + cal(i + 1, r));
    }
    // cout << l << " " << r << " " << res << endl;
    return res;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("daruma.inp", "r")) {
        freopen("daruma.inp", "r", stdin);
        freopen("daruma.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        if (n == 0){
            return 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << cal(1,n) << endl;
    }
    return 0;
}
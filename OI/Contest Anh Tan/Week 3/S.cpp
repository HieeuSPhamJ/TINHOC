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

const int maxN = 1e3 + 10;

int a[maxN];
int dp[maxN][maxN][2];
int nxtl[maxN];
int nxtr[maxN];

int cal(int l, int r, int cost = 1){
    if (dp[l][r][cost] != 0){
        return dp[l][r][cost];
    }
    if (l > r){
        return 0;
    }
    if (l == r){
        return dp[l][r][cost] = 1;
    }
    int &res = dp[l][r][cost] = min(cal(l + 1, r), cal(l, r - 1)) + 1;
    // cout << l << " " << r << ": " << res << endl;
    for (int mid = l + 1; mid <= r; mid++){
        if (a[l] == a[mid]){
            int tres = cal(l + 1, mid - 1) + cost + min(cal(mid, r, 0),  cal(mid + 1, r));
            // cout << l << " " << mid << ' ' << r << " " << cost << ": " << tres << endl;
            // cout << " " << cal(l + 1, mid - 1) + cost << " " << cal(mid, r, 0) << endl;
            res = min(res, tres); 
        }
    }
    return res;
}

/*
12345678
010212
3031323
14151232

*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DELSTR.inp", "r")) {
        freopen("DELSTR.inp", "r", stdin);
        freopen("DELSTR.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // for (int i = 1; i <= n; i++){
    //     cout << a[i];
    // }
    // cout << endl;
    cout << cal(1,n) << endl;
    return 0;
}

/*
1234567890
abaaaccbcc
*/
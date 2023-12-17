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


int cal(int l, int r){
    int &res = dp[l][r];
    if (l > r){
        return 0;
    }
    if (res){
        return res;
    }
    if (l == r){
        res = a[l - 1] * a[l] * a[l + 1];
        cout << l << " " << r << ": " << res << endl;
        return res;
    }
    if (l + 1 == r){
        res = max(a[l - 1] * a[l] * a[r] + a[l - 1] * a[r] * a[r + 1],
                a[l] * a[r] * a[r + 1] + a[l - 1] * a[l] * a[r + 1]
        );
        cout << l << " " << r << ": " << res << endl;
        return res;
    }
    for (int i = l + 1; i < r; i++){
        maximize(res, cal(l, i - 1) + cal(i + 1, r) + a[l] * a[i] * a[r]);
    }
    cout << l << " " << r << ": " << res << endl;
    return res;
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
    cout << cal(1,n);
    return 0;
}
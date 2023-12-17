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

int dp[110][110][110];
int a[110];
int price[110];

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

int cal(int l, int r, int cost = 1){
    if (l > r){
        return 0;
    }
    int &res = dp[l][r][cost];
    if (res){
        // cout << l << " " << r << " " << cost << ": " << res << endl;
        return res;
    }

    if (l == r){
        res = price[cost];
        // cout << l << " " << r << " " << cost << ": " << res << endl;
        return res;
    }
    if (cost > 1){
        res = 1 + cal(l, r - 1, cost);
        if (a[l] == a[l + 1]){
            maximize(res, price[cost] + cal(l + 1, r, cost));
        }
        else{
            maximize(res, price[cost] + cal(l + 1, r));
        }
    }
    else{
        res = max(1 + cal(l + 1, r), 1 + cal(l, r - 1));
    }

    for (int i = l + 1; i <= r; i++){
        if (a[l] == a[i]){
            maximize(res, cal(l + 1, i - 1) + cal(i, r, cost + 1) + price[cost]);
            // cout << "!" << l << " " << r << " " << cost << ": " << endl;
            // cout << l  + 1 << "," << i - 1 << "," << cost << " " << i << "," << r << "," << cost + 1 << endl;
            // cout << " " << dp[l + 1][i - 1][1] << " " << dp[i][r][cost + 1] << " " << price[cost] << endl;
        }
    }


    // cout << l << " " << r << " " << cost << ": " << res << endl;
    return res;
}

/*
1 2 3 4 5 6 7 8 9
1 3 2 2 2 3 4 3 1
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        price[i] = i * i;
    }
    for (int i = n; i >= 1; i--){
        price[i] -= price[i - 1];
    }

    // for (int i = 1; i <= n; i++){
    //     cout << price[i] << endl;
    // }

    cout << cal(1,n);
    return 0;
}
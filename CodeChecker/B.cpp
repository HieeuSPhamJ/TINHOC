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

<<<<<<< HEAD
struct node{
    int t,p1,p2,p3,p4;
};

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
=======
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
>>>>>>> 1c3fc3d43b04e0ee5a2fdac54a286c985133144b
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

int dp[110][110];
int a[110][110];
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
<<<<<<< HEAD
    int n, m;
    cin >> n >> m;
    memset(a, -1,sizeof(a));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int test = 4;
    int res = 0;
    while(test--){
        memset(dp, -1,sizeof(dp));
        dp[1][1] = a[1][1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                maximize(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
                maximize(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            }
        }
        res += dp[n][m];
        ii t = {n,m};
        while(t != ii(1,1)){
            int la = dp[t.fi][t.se] - a[t.fi][t.se];
            a[t.fi][t.se] = 0;
            if (dp[t.fi - 1][t.se] == la){
                t.fi--;
                continue;
            }
            if (dp[t.fi][t.se - 1] == la){
                t.se--;
                continue;
            }
            // cout << t.fi << " " << t.se << " " << la << endl;
        }
        a[1][1] = 0;
    }
    cout << res << endl;
=======
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
>>>>>>> 1c3fc3d43b04e0ee5a2fdac54a286c985133144b
    return 0;
}
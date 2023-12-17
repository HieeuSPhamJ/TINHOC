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

const int maxN = 2000 + 10;

int dp[maxN][maxN];
ii pre[maxN];
int a[maxN][maxN];

void insert(ii &s, int x){
    if (s.fi == -1){
        s.fi = x;
        return;
    }
    if (s.se == -1){
        s.se = x;
        if (s.fi > s.se){
            swap(s.fi,s.se);
        }
        return;
    }
    if (x < s.fi){
        s.se = s.fi;
        s.fi = x;
        return;
    }
    if (x < s.se){
        // cout << "*" << endl;
        s.se = x;
        return;
    }
}

void erase(ii &s, int x){
    if (s.fi == x){
        s.fi = s.se;
        s.se = -1;
        return;
    }
    if (s.se == x){
        s.se = -1;
        return;
    }
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
    int n, m;
    cin >> n >> m;
    ii x = {3,-1};
    insert(x,1);
    // cout << x.fi << " " << x.se << endl;
    // // cout << x.fi << " " << x.se << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++){
        dp[0][i] = 0;
    }
    pre[0] = {0,0};
    for (int i = 1; i <= n; i++){
        pre[i] = {-1, -1};
        for (int j = 1; j <= m; j++){
            // cout << i << " " << j << ": " << endl;
            ii s = pre[i - 1]; 
            erase(s, dp[i - 1][j]);
            dp[i][j] = s.fi + a[i][j];
            insert(pre[i], dp[i][j]);
            // cout << s.fi << " " << s.se << endl;
        //     cout << dp[i][j] << endl;
        // cout << pre[i].fi << " " << pre[i].se << endl;
        }
    }
    cout << pre[n].fi << endl;
    return 0;
}
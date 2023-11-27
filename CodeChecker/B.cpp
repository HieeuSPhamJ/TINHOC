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

int n;
int a[maxN][maxN];
int b[maxN][maxN];
int pre[2][maxN];
ii dp[maxN][maxN];

int callo(){
    cout << "With: " << endl;
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            pre[0][j] = pre[0][j - 1] + a[i][j] * (j % 2 == 0);
            pre[1][j] = pre[1][j - 1] + a[i][j] * (j % 2);
            dp[i][j] = {0,0};
        }
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
        for (int j = 1; j <= n; j++){
            cout << pre[0][j] << " ";
        }
        cout << endl;
        for (int j = 1; j <= n; j++){
            cout << pre[1][j] << " ";
        }
        cout << endl;
        for (int j = 2; j <= n; j+=2){
            // tres = max(tres, pre[0][j] + pre[1][n] - pre[1][j + 1]);
            // tres = max(tres, pre[1][j] + pre[0][n] - pre[0][j]);
            // cout << j << ": " << pre[0][j] + pre[1][n] - pre[1][j + 1] << " " << pre[1][j] + pre[0][n] - pre[0][j] << endl;
        }

        // for (int j = 1; j <= n; j++){
        //     dp[]
        // }
    }
    // cout << res << endl;
    return res;
}

int cal(){
    int res = 0;
    for (int i = 1; i <= n; i++){
        int s[2];
        s[0] = 0;
        s[1] = 0;
        for (int j = 1; j <= n; j++){
            s[j % 2] += a[i][j];
        }
        res += max(s[0], s[1]);
    }
    return res;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SPACED.inp", "r")) {
        freopen("SPACED.inp", "r", stdin);
        freopen("SPACED.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int res = 0;
    res = max(res, cal());
    swap(a,b);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = b[j][i];
        }
    }
    res = max(res, cal());
    cout << res << endl;
    return 0;
}
/*
1 x x 1 
x 1 1 1 
1 x x 2 
x 1 2 2 

.x.x
x.x.
x..x 1
.xx.

*/
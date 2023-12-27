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

const int maxN = 130;
const int mod = 1e9 + 7;


int n, m, k;
int dp[maxN][maxN][maxN];
int a[maxN][maxN];
int pre[maxN][maxN];
int lai[maxN];

int add(int x, int y){
    return (x + y) % mod;
}
int sub(int x, int y){
    return (x - y + mod) % mod;
}


int bit[maxN][maxN][maxN];

void update(int i, int j, int t, int v){
    int x = i;
    while(x <= n){
        int y = j;
        while(y <= m){
            bit[x][y][t] = add(bit[x][y][t], v);
            y += y & (-y);
        }
        x += x & (-x);
    }
}

int get(int i, int j, int t){
    int x = i;
    int res = 0;
    while(x){
        int y = j;
        while(y){
            res = add(res, bit[x][y][t]);
            y -= y & (-y);
        }
        x -= x & (-x);
    }
    return res;
}

void print(int t){
    cout << "==" << t << "==" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << dp[i][j][t] << " ";
        }
        cout << endl;
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
    cin >> n >> m >> k;
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            cin >> a[i][j];
            a[i][j] = (a[i][j] == 2);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1, laj = 0; j <= m; j++){
            if (pre[i][j] - pre[i][j - 1]){
                laj = j;
            }
            if (pre[i][j] - pre[i - 1][j]){
                lai[j] = i;
            }
            for (int t = k; t >= 2; t--){
                if (!laj and !lai[j]){
                    continue;
                }
                int &cur = dp[i][j][t];
                // print(t - 1);   
                // cout << i << " " << j << " " << t << ": " << endl;
                // cout << laj << " " << lai[j] << endl;
                if (laj){
                    cur = add(cur, sub(get(i,laj - 1, t - 1), get(i - 1, laj - 1, t - 1)));
                }
                if (lai[j]){
                    cur = add(cur, sub(get(lai[j] - 1, j, t - 1), get(lai[j] - 1, j - 1, t - 1)));
                }
                // if (cur){
                //     cout << cur << endl; 
                // }
                update(i,j,t,cur);
            }
            if (lai[j] or laj){
                dp[i][j][1] = 1;
                update(i,j,1,dp[i][j][1]);
            }
        }
    }
    // cerr << get(3,1,1) << " " << get(2,1,1) << endl;
    // cerr << get(2,2,1) << " " << get(2,1,1) << endl;
    cout << dp[n][m][k];
    return 0;
}

/*
laj: dp[i][k]: k < laj
lai: dp[k][j]: k < lai
*/
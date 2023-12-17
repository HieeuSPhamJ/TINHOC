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

const int maxN = 210;

int n, m;
int dp[maxN][maxN][maxN];
int a[maxN][maxN];

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

int res = 0;

void print(int i, int j, int u, int v){
    cout << i << " " << j << " " << u << " " << v << ": " << dp[i][j][u] << endl;
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= m; y++){
            if ((x == i and y == j) or (x == u and y == v)){
                cout << "@" << " ";
            }
            else{
                cout << "." << " ";
            }
        }
        cout << endl;
    }
}

bool moveto(int i, int j, int u, int cur){
    int v = i + j - u;
    if (i < 1 or j < 1 or u < 1 or v < 1){
        return 0;
    }
    if (i > n or j > m or u > n or v > m){
        return 0;
    }
    int co = a[i][j];
    if (ii(i,j) != ii(u,v)){
        co += a[u][v];
    }
    int t = maximize(dp[i][j][u], cur + co);
    if (t){
        // print(i,j,u,v);
    }
    return t;
}

/*

3 1 1
2 5 1
1 5 5
2 1 1

3 + 2 + 1 + 2 + 1 + 1
  + 1 + 5 + 5 + 5
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    dp[1][1][1] = a[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= n; k++){
                int cur = dp[i][j][k];
                if (cur == 0){
                    continue;
                }
                // cout << "With: ";     
                // print(i, j, k, i + j - k);
                moveto(i + 1, j, k + 1, cur);
                moveto(i + 1, j, k, cur);
                moveto(i, j + 1, k + 1, cur);
                moveto(i, j + 1, k, cur);
            }
        }
    }
    cout << dp[n][m][n] << endl;
    return 0;
}
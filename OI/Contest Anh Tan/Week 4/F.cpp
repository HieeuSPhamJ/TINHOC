#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2010;

int a[maxN][maxN];
int cheosum[2][maxN][maxN];
int cheosub[2][maxN][maxN];
int ngang[2][maxN][maxN];
int doc[2][maxN][maxN];

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
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == '.'){
                a[i][j] = 1;
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j]){
                cheosum[0][i][j] = cheosum[0][i - 1][j - 1] + 1;
                cheosub[0][i][j] = cheosub[0][i - 1][j + 1] + 1;
                ngang[0][i][j] = ngang[0][i][j - 1] + 1;
                doc[0][i][j] = doc[0][i - 1][j] + 1;
            }
        }
    }
    
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            if (a[i][j]){
                cheosum[1][i][j] = cheosum[1][i + 1][j + 1] + 1;
                cheosub[1][i][j] = cheosub[1][i + 1][j - 1] + 1;
                ngang[1][i][j] = ngang[1][i][j + 1] + 1;
                doc[1][i][j] = doc[1][i + 1][j] + 1;
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << doc[0][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int res = cheosub[0][i][j] + cheosub[1][i][j];
            res += cheosum[0][i][j] + cheosum[1][i][j];
            res += ngang[0][i][j] + ngang[1][i][j];
            res += doc[0][i][j] + doc[1][i][j];
            if (res){
                res -= 7;
            }
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
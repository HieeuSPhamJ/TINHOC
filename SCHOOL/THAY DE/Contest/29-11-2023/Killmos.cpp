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

int a[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Killmos.inp", "r")) {
        freopen("Killmos.inp", "r", stdin);
        freopen("Killmos.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == '*'){
                a[i][j] = 1;
            }
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]; 
            // cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int res = 0;
    k -= 2;
    if (k <= 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i = k + 1; i < n; i++){
        for (int j = k + 1; j < m; j++){
            res = max(res, a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k]);
        }
    }

    cout << res << endl;

    return 0;
}
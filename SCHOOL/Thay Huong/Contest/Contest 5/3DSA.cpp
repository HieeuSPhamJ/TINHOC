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

const int maxN = 1010;

int a[maxN][maxN];
ii d[] = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("3DSA.inp", "r")) {
        freopen("3DSA.inp", "r", stdin);
        freopen("3DSA.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int tres = 1;
            for (int x = 0; x < 4; x++){
                tres += max(0ll, a[i][j] - a[i + d[x].fi][j + d[x].se]);
            }
            res += tres;
        }
    }
    cout << res + n * m << endl;
    return 0;
}

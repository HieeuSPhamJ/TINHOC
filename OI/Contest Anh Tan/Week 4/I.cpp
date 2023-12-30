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

const int maxN = 500 + 10;

int a[maxN][maxN];
int b[maxN];

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
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int l = 1; l <= n; l++){
        for (int i = 1; i <= m; i++){
            b[i] = 0;
        }
        for (int r = l; r <= n; r++){
            for (int i = 1; i <= m; i++){
                if (b[i] == 0 or b[i] == a[r][i]){
                    b[i] = a[r][i];
                }
                else{
                    b[i] = -1;
                }
            }
            for (int i = 1, t = 1; i <= m; i++){
                if (b[i] == b[i - 1]){
                    t++;
                }
                else{
                    t = 1;
                }
                if (b[i] == -1){
                    t = 0;
                }
                res = max(res, (r - l + 1) * t);
                // cout << l << " " << r << " " << t << ": " << res << endl;

            }
        }
    }
    cout << res << endl;
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN][maxN];
int pre[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 1e18;
    for (int i = 1; i < n; i++){
        int dif = 1e18;
        int c1 = 1e18;
        int c2 = 1e18;
        int c3 = 1e18;
        int c4 = 1e18;
        
        for (int j = 1; j < m; j++){
            if (abs((pre[i][m] - pre[i][j]) - pre[i][j]) < dif){
                dif = abs((pre[i][m] - pre[i][j]) - pre[i][j]);
                c1 = min(pre[i][m] - pre[i][j], pre[i][j]);
                c2 = max(pre[i][m] - pre[i][j], pre[i][j]);
            }
        }
        dif = 1e18;

        for (int j = 1; j < m; j++){
            int temp = abs((pre[n][m] - pre[i][m]) - (pre[n][j] - pre[i][j]) - (pre[n][j] - pre[i][j]));
            if (temp < dif){
                dif = temp;
                c3 = min(pre[n][j] - pre[i][j], (pre[n][m] - pre[i][m]) - (pre[n][j] - pre[i][j]));
                c4 = max(pre[n][j] - pre[i][j], (pre[n][m] - pre[i][m]) - (pre[n][j] - pre[i][j]));
            }
        }
        // cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
        ans = min(ans, max({c1,c2,c3,c4}) - min({c1,c2,c3,c4}));
    }
    cout << ans << endl;
    return 0;
}
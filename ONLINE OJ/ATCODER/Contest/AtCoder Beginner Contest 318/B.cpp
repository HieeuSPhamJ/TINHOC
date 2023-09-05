#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int grid[110][110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = a; x <= b - 1; x++){
            for (int y = c; y <= d - 1; y++){
                grid[x][y] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= 101; i++){
        for (int j = 0; j <= 101; j++){
            // cout << grid[i][j];
            res += grid[i][j];
        }
        // cout << endl;
    }
    cout << res << endl;
    return 0;
}
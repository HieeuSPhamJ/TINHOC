#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 22;

map <int,int> dp1[21][maxN];
map <int,int> dp2[22][maxN];

int a[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }   
    dp1[1][1][a[1][1]] = 1;
    
    for (int i = 1; i <= n / 2; i++){
        for (int j = 1; j <= m; j++){
            // cout << i << ' ' << j << endl;
            for (auto cur: dp1[i][j]){
                dp1[i + 1][j][cur.fi xor a[i + 1][j]] += cur.se;
                dp1[i][j + 1][cur.fi xor a[i][j + 1]] += cur.se;       
            }
            dp1[i - 1][j].clear();
        }
    }
    const int asd = n / 2;
    dp2[n - asd][m][a[n][m]] = 1;
    for (int i = n; i >= n / 2 + 1; i--){
        for (int j = m; j >= 1; j--){
            for (auto cur: dp2[i - asd][j]){
                // cout << i << ' ' << j << ' ' << cur.fi << " " << cur.se << endl;
                dp2[i - 1 - asd][j][cur.fi xor a[i - 1][j]] += cur.se;
                dp2[i - asd][j - 1][cur.fi xor a[i][j - 1]] += cur.se;       
            }
            dp2[i + 1 - asd][j].clear();
        }
    }
    
    if (n == 1){
        cout << dp2[1][1][k] << endl;
        return 0;
    }

    int res = 0;

    for (int i = 1; i <= m; i++){
        for (auto cur: dp1[n / 2][i]){
            // cout << n / 2 << " " << i << ": " << cur.fi << ' ' << cur.se << endl;
            // cout << "*" << n / 2 + 1 << " " << i << ": " << cur.fi << " " << dp2[n / 2 + 1][i][cur.fi] << endl;
            res += cur.se * dp2[n / 2 + 1 - asd][i][cur.fi xor k];
            
        }
    }

    
    cout << res << endl;

    // cout << dp1[n][m][k] << " " << dp2[1][1][k];
    return 0;
}

/*
3 3 4 1
3 2 2 1
3 1 14 1
2 3 4 1
2 2 8 1
2 2 14 1
2 1 9 2
2 1 15 1
*/
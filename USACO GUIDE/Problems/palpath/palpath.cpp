#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

int a[510][510];
int dp[510][510][510];

signed main(){
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c;
            cin >> c;
            a[i][j] = c - 'A';
        }
    }
    dp[1][1][n] = (a[1][1] == a[n][n]);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int x = n; x >= 1; x--){
                int y = n + 1 - i - j + (n - x + 1);
                int curr = dp[i][j][x];
                
                if (max(i,j) > min(x,y)){
                    continue;
                }
                if (curr == 0){
                    continue;
                }
                // cout << i << ' ' << j << " " << x << ' ' << y << " " << curr << endl;
                if (a[i + 1][j] == a[x - 1][y]){
                    (dp[i + 1][j][x - 1] += curr) %= mod;
                }
                if (a[i][j + 1] == a[x - 1][y]){
                    (dp[i][j + 1][x - 1] += curr) %= mod;
                }
                if (a[i + 1][j] == a[x][y - 1]){
                    (dp[i + 1][j][x] += curr) %= mod;
                }
                if (a[i][j + 1] == a[x][y - 1]){
                    (dp[i][j + 1][x] += curr) %= mod;
                }
                
            }
        }
    }
    int res = 0;
    if (n % 2 == 0){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                (res += dp[i][j][i]) %= mod;
            }
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                (res += dp[i][j][i] + dp[i][j][i + 1]) %= mod;
            }
        }
    }

    cout << res << endl;
    return 0;
}

/*
x = 1
xx = n - x + 1
i + j = x + y
i + j - (n - x + 1) = n - y + 1
i + j - (n - x + 1) = n - y + 1
y = n + 1 - i - j + (n - x + 1)
1 + 1 - (4 - 4 + 1) = 4 - 4 + 1
*/
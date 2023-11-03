#include <bits/stdc++.h>
#define int long long
#define double long double
#define ii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 111539786;

int a[110][12];
int dp[110][12][3010];

void add(int &a, int b){
    (a += b) %= mod;
}

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= s; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int c = 0; c <= 3000; c++){
                if (c >= 2){
                    if (j > 1){
                        add(dp[i][j][c], dp[i][j - 1][c - 2]);
                    }
                    else{
                        add(dp[i][j][c], dp[i - 1][m][c - 2]);
                    }
                }
                if (c >= 1){
                    if (a[i][j] != 1 and j != m and a[i][j + 1] != 1){
                        if (j == 1){
                            add(dp[i][j][c], dp[i - 1][m][c - 1]);
                        }
                        else{
                            add(dp[i][j][c], dp[i][j - 1][c - 1]);
                        }
                    }
                    if (a[i][j] != 1 and i != n and a[i + 1][j] != 1){
                        if (j == 1){
                            add(dp[i][j][c], dp[i - 1][m][c - 1]);
                        }
                        else{
                            add(dp[i][j][c], dp[i][j - 1][c - 1]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][m][s + k - 2 + (n + 1) * (m + 1) - n - m + 1] << endl;
}
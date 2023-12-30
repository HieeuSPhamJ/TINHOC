#include <bits/stdc++.h>

using namespace std;

const int N = 401;
int n, a[N][N], m;
short p[N][N*N], dp[N][N][N];

int main () 
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int l = m; l >= 1; l--)
      for (int r = l; r <= m; r++) {
        if (l == r) {
          dp[i][l][r] = max(dp[i - 1][l][r], p[l][a[i][l]]);
        }
        else {
          dp[i][l][r] = max({dp[i][l + 1][r], dp[i][l][r - 1], dp[i - 1][l][r], p[r][a[i][l]], p[l][a[i][r]]});
          if (a[i][l] == a[i][r])
            dp[i][l][r] = i;
        }
        ans = max(ans, (i - dp[i][l][r]) * (r - l + 1));
      }
    for (int j = 1; j <= m; j++)
      p[j][a[i][j]] = i;
  }
  cout << ans << endl;
  return 0;
}
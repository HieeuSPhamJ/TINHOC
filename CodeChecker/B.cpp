#include <bits/stdc++.h>
using namespace std;

constexpr int nmax = 3030;
int hole[nmax][nmax];
int dp[nmax][nmax];

int main() {
freopen("input.inp", "r", stdin);
freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, N;
  cin >> H >> W >> N;
  for (int i = 0, a, b; i < N; i++) {
    cin >> a >> b, hole[a][b] = 1;
  }
  long long ans = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (hole[i][j]) continue;
      dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
      ans += dp[i][j];
    }
  }
  cout << ans << "\n";
}

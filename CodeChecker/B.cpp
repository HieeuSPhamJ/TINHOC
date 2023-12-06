#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN ((1 << 18) + 10)
#define MAXSZ 70

int dp[MAXSZ + 1][MAXN];
int A[MAXN];

int main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
  int N; cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = 0;
  for (int i = 0; i <= MAXSZ; i++) {
    for (int j = 0; j < N; j++) {
      if (A[j] == i) {
        dp[i][j] = j + 1;
        result = max(result, i);
      } else {
        if (i == 0 || dp[i - 1][j] == -1 || dp[i - 1][dp[i - 1][j]] == -1) {
          dp[i][j] = -1;
        } else {
          dp[i][j] = dp[i - 1][dp[i - 1][j]];
          result = max(result, i);
        }
      }
    }
    dp[i][N] = -1;
  }
  cout << result << endl;

  return 0;
}
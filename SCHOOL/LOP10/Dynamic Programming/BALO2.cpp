#include <iostream>

using namespace std;

int n, W;
int dp[1001][1001];
int w[1001], v[1001];

void ddi(int x, int y) {
	if (x && y) {
		if (dp[x - 1][y] == dp[x][y]) {
			ddi(x - 1, y);
		}
		else {
			ddi(x - 1, y - w[x]);
			cout << w[x] << " " << v[x] << "\n";
		}
	}
}

int main() {
	freopen("BALO2.INP", "r", stdin);
	freopen("BALO2.OUT", "w", stdout);

	cin >> n >> W;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][W] << "\n";
	ddi(n, W);
}
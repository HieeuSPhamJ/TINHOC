#include <iostream>

using namespace std;

int n, W;
int a[10000];
int dp[10000][10000];

void ddi(int x, int y) {
	if (x > 0 && y > 0) {
		if (dp[x - 1][y] == dp[x][y]) {
			ddi(x - 1, y);
		}
		else {
			ddi(x - 1, y - a[x]);
			cout << a[x] << " ";
		}
	}
	return;
}

int main() {
	freopen("BALO1.INP", "r", stdin);
	freopen("BALO1.OUT", "w", stdout);

	cin >> n >> W;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= a[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][W] << "\n";

	ddi(n, W);

	return 0;	
}


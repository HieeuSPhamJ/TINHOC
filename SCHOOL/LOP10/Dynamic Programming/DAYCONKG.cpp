#include <iostream>

using namespace std;

int n;
int a[1003];
int trc[1003];
int dp[1003];

void path(int u) {
	if (dp[u] > 1) {
		path(trc[u]);
	}
	cout << a[u] << " ";
}

int main() {
	freopen("DAYCONKG.INP", "r", stdin);
	freopen("DAYCONKG.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}	

	int ansIndex = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] <= a[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					trc[i] = j;
				}
			}
		}
		if (dp[i] > dp[ansIndex]) {
			ansIndex = i;
		}
	}

	cout << dp[ansIndex] << "\n";

	path(ansIndex);
	
	return 0;
}
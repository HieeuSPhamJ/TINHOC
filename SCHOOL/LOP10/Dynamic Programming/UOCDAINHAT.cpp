#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000006];
int dp[1000006];
int trc[1000006];

void ddi(int x) {
	if (trc[x] == 0) {
		cout << a[x];
		return;
	}
	ddi(trc[x]);
	cout << " " << a[x];
}

int main() {
	freopen("UOCDAINHAT.INP", "r", stdin);
	freopen("UOCDAINHAT.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

	int ansIndex = 1;
	sort(a + 1, a + n + 1);

	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j; j--) {
			if (a[i] % a[j] == 0 && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				trc[i] = j;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dp[i] > dp[ansIndex]) {
			ansIndex = i;
		}
	}

	cout << dp[ansIndex] << "\n";

	ddi(ansIndex);
}
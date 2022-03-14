#include <iostream>

using namespace std;

int n;
int a[1003];
int last[1003];
int dp[1003];

void path(int u) {
	if (dp[u] > 1) {
		path(last[u]);
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
	int index = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] <= a[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					last[i] = j;
				}
			}
		}
		if (dp[i] > dp[index]) {
			index = i;
		}
	}
	cout << dp[index] << endl;

	path(index);
	
	return 0;
}
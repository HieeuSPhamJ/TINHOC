#include <iostream>

using namespace std;

string s1, s2;

int dp[10001][10001];

void ddi(int x, int y) {
	if (x && y) {
		if (s1[x - 1] == s2[y - 1]) {
			ddi(x - 1, y - 1);
			cout << s1[x - 1];
		}
		else {
			if (dp[x - 1][y] > dp[x][y - 1]) {
				ddi(x - 1, y);
			} 
			else {
				ddi(x, y - 1);
			}
		}
	}
}

int main() {
	freopen("XAUCONCHUNG.INP", "r", stdin);
	freopen("XAUCONCHUNG.OUT", "w", stdout);

	cin >> s1 >> s2;

	for (int i = 1; i <= (int) s1.size(); i++) {
		for (int j = 1; j <= (int) s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << "\n";

	ddi(s1.size(), s2.size());

	return 0;
}
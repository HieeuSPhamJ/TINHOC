#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length();
	
	// dp[i][j] = number of palidrome substrings in [i,j]
	vector<vector<int>> dp(n, vector<int>(n));
	
	// pal[i][j] = true if [i,j] is a palindrome
	vector<vector<bool>> pal(n, vector<bool>(n));

	for (int i = n - 1; i >= 0; i--) {
		// base case: strings of length 1 are always a palindrome
		dp[i][i] = pal[i][i] = 1;
		for (int j = i + 1; j < n; j++) {
			/*
			 * We add a character before start and after the end.
			 * If previously was a palindrome and the new characters
			 * are the same, then it is still a palindrome.
			 */
			pal[i][j] = (pal[i + 1][j - 1] || j - i == 1)
						&& (s[i] == s[j]);

			// number of palindromes using inclusion - exclusion
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1]
					    - dp[i + 1][j - 1] + pal[i][j];
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; 
		cin >> l >> r;
		cout << dp[l - 1][r - 1] << "\n";
	}
}
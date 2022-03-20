#include <iostream>

using namespace std;

int n;
bool a[10001];
string s;

bool check() {
	int open = 0;
	int close = 0;
	for (int i = 0; i < n; i++) {
		if (close > open) {
			return false;
		}
		open += (s[i] == '(');
		close += (s[i] == ')');
	}
	return (close == open);
}

void backTracking(int d) {
	if (d > n) {
		s = "";
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				s += ")";
			}
			else {
				s += "(";
			}
		}

		if (check()) {
			cout << s << "\n";
		}
	}
	else {
		for (int i = 0; i <= 1; i++) {
			a[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("BAI47QL.INP", "r", stdin);
	freopen("BAI47QL.OUT", "w", stdout);

	cin >> n;

	n *= 2;
	backTracking(1);

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

string s;
int a[1001];
bool check[1001];

void backTracking(int d) {
	if (d > (int) s.size()) {
		for (int i = 1; i <= s.size(); i++) {
			cout << s[a[i] - 1];
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= s.size(); i++) {
			if (!check[i]) {
				check[i] = true;
				a[d] = i;
				backTracking(d + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	freopen("BAI43QL.INP", "r", stdin);
	freopen("BAI43QL.OUT", "w", stdout);

	cin >> s;

	backTracking(1);

	return 0;
}
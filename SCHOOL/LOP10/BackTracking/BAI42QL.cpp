#include <iostream>

using namespace std;

int n;
bool a[20];

void backTracking(int d) {
	if (d > n) {
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i <= 1; i++) {
			a[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("BAI42QL.INP", "r", stdin);
	freopen("BAI42QL.OUT", "w", stdout);

	cin >> n;

	backTracking(1);

	return 0;
}
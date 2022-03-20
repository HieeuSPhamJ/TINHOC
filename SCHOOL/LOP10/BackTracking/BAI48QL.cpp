#include <iostream>

using namespace std;

int n;
int a[10001];
bool c[100001];
bool b[100001];

void backTracking(int d) {
	if (d > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i]) {
				sum += a[i];
			}
		}
		b[sum] = true;
	}
	else {
		for (int i = 0; i <= 1; i++) {
			c[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("BAI48QL.INP", "r", stdin);
	freopen("BAI48QL.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	backTracking(1);

	for (int i = 1; i <= 1000; i++) {
		if (!b[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
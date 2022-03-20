#include <iostream>

using namespace std;

int n;
int a[10001];
bool b[10001];
int ans = 0;

void backTracking(int d) {
	if (d > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i]) {
				sum += a[i];
			}
			else {
			 	sum -= a[i];
			}
		}
		ans += (!sum);
	}
	else {
		for (int i = 0; i <= 1; i++) {
			b[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("DOIDAU.INP", "r", stdin);
	freopen("DOIDAU.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	backTracking(1);

	cout << ans;

	return 0;
}
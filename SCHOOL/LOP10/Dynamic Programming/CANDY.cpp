#include <iostream>

using namespace std;

int n;
int a[1003];
bool b[1000006];

int main() {
	freopen("CANDY.INP", "r", stdin);
	freopen("CANDY.OUT", "w", stdout);

	int sum = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	b[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= a[i]; j--) {
			if (!b[j] && b[j - a[i]]) {
				b[j] = true;
			}
		}
	}

	int ans = sum;

	for (int i = 1; i < sum; i++) {
		if (b[i]) {
			ans = min(ans, abs((sum - i) - i));
		}
	}

	cout << ans;
}
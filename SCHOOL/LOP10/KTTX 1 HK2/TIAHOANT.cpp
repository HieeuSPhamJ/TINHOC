#include <iostream>

using namespace std;

int n;
int a[10001];
bool b[100001];
int ans = 0;

bool prime(int n) {
	if (n <= 1) {
		return false;
	}
	
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void backTracking(int d) {
	if (d > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) { 
			if (b[i]) {
				sum += a[i];
			}
		}
		ans += prime(sum);
	}
	else {
		for (int i = 0; i <= 1; i++) {
			b[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("TIAHOANT.INP", "r", stdin);
	freopen("TIAHOANT.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	backTracking(1);

	cout << ans;

	return 0;
}
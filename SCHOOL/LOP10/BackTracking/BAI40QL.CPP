#include <iostream>

using namespace std;

long long n;
bool ok = false;

bool prime(long long n) {
	if (n == 1) {
		return false;
	}
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void backTracking(long long d, long long x) {
	if (d == n) {
		ok = true;
		cout << x << endl;
	}
	else {
		for (long long i = 1; i <= 9; i++) {
			if (prime(x * 10 + i)) {
				backTracking(d + 1, x * 10 + i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("BAI40QL.INP", "r", stdin);
	freopen("BAI40QL.OUT", "w", stdout);

	cin >> n;

	for (int i = 2; i <= 9; i++) {
		if (prime(i)) {
			backTracking(1, i);
		}
	}

	if (!ok) {
		cout << -1;
	}

	return 0;
}
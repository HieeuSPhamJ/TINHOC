#include <iostream>

using namespace std;

long long n, k;
long long a[1001];
long long b[1001];
long long sum[1001];
bool ok = false;

void xuat() {
	for (long long i = 1; i <= k; i++) {
		for (long long j = 1; j <= n; j++) {
			if (b[j] == i) {
				cout << a[j] << " ";
			}
		}
		cout << "\n";
	}
}

bool check() {
	for (long long i = 2; i <= k; i++) {
		if (sum[i] != sum[i - 1]) {
			return false;
		}
	}
	return true;
}

void backTracking(long long d) {
	if (!ok) {
		if (d > n) {
			for (long long i = 1; i <= n; i++) {
				sum[b[i]] += a[i];
			}
			if (check()) {
				ok = true;
				xuat();
			}
			for (long long i = 1; i <= n; i++) {
				sum[i] = 0;
			}
		}
		else {
			for (long long i = 1; i <= k; i++) {
				b[d] = i;
				backTracking(d + 1);
			}
		}
	}
}

int main() {
	freopen("BAI45QL.INP", "r", stdin);
	freopen("BAI45QL.OUT", "w", stdout);
	
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	backTracking(1);

	if (!ok) {
		cout << -1;
	}

	return 0;
}
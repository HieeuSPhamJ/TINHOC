#include<bits/stdc++.h>
using namespace std;


int main() {
	freopen( "PSNGUYEN.INP", "r", stdin );
	freopen( "PSNGUYEN.OUT", "w", stdout );
    long long m, n;
	cin >> m >> n;
	long long ans = 0;
	for (long long i = 1; i < n; i++) {
		ans += abs(m / (n + i) - (2 * m - 1) / (n + i));
	}
	cout << ans;
	return 0;
}
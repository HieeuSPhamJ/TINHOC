#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {


		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int k;
		cin >> k;
		vector<int> b(k);
		for (int i = 0; i < k; i++) {
			cin >> b[i];
		}
		vector<pair<int, long long>> x;
		for (int i = 0; i < n; i++) {
			int val = a[i];
			long long cur = 1;
			while (val % m == 0) {
				val /= m;
				cur *= m;
			}
			if (x.size() && val == x.back().first) {
				x.back().second += cur;
			} else {
				x.emplace_back(val, cur);
			}
		}

		vector<pair<int, long long>> y;
		for (int i = 0; i < k; i++) {
			int val = b[i];
			long long cur = 1;
			while (val % m == 0) {
				val /= m;
				cur *= m;
			}
			if (y.size() && val == y.back().first) {
				y.back().second += cur;
			} else {
				y.emplace_back(val, cur);
			}
		}
		cout << (x == y ? "YES" : "NO") << '\n';
	}
	return 0;
}
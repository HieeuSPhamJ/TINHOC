#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int unmask(int mask, const vector<int> &arr, int mod) {
	int current_sum = 0;
	for (int bit = 0; bit < arr.size(); bit++) {
		if ((mask >> bit & 1) == 1) {
			current_sum += arr[bit];
			current_sum %= mod;
		}
	}
	return current_sum;
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> left_arr((n + 1) / 2);
	vector<int> right_arr(n / 2);
	for (int &i : left_arr) {
		cin >> i;
	}
	for (int &i : right_arr) {
		cin >> i;
	}

	set<int> left_sums;
	for (int mask = 0; mask < (1 << left_arr.size()); mask++) {
		left_sums.insert(unmask(mask, left_arr, m));
	}

	int best = *left_sums.rbegin();
	for (int mask = 0; mask < (1 << right_arr.size()); mask++) {
		int current_sum = unmask(mask, right_arr, m);
		best = max(
			best, 
			*prev(left_sums.lower_bound(m - current_sum)) + current_sum
		);
	}

	cout << best << endl;
}
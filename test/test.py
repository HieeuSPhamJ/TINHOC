#include <bits/stdc++.h>
using namespace std;

/**
 * Calculate the sum of all elements in arr, represented by the binary mask, and
 * take modulo mod.
 */
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

int main() {
	int n, m;
	cin >> n >> m;

	// split the input array into two parts
	vector<int> left_arr((n + 1) / 2);
	vector<int> right_arr(n / 2);
	for (int &i : left_arr) {
		cin >> i;
	}
	for (int &i : right_arr) {
		cin >> i;
	}

	// stores the sums of all combinations from the left_arr modulo m
	set<int> left_sums;
	for (int mask = 0; mask < (1 << left_arr.size()); mask++) {
		left_sums.insert(unmask(mask, left_arr, m));
	}

	// the best value from all combinations of left_arr
	int best = *left_sums.rbegin();
	for (int mask = 0; mask < (1 << right_arr.size()); mask++) {
		int current_sum = unmask(mask, right_arr, m);
		/*
		 * a possible new maximum value is the sum of current_sum and the largest
		 * value below m - current_sum from the combinations in left_arr
		 */
		best = max(
			best, 
			*prev(left_sums.lower_bound(m - current_sum)) + current_sum
		);
	}

	cout << best << endl;
}
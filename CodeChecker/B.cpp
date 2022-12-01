#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.inp", "r", stdin);
    // freopen("B.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	deque<int> rooms(n);
	for (int &r : rooms) {
		cin >> r;
	}

	long long min_dist = INT64_MAX;
	// Iterate through all possible positions of the first door
	for (int start_pos = 0; start_pos < n; start_pos++) {
		vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INT64_MAX));
		// With no door used, the distance is only zero if there is no room filled
		dp[0][n] = 0;
		// Iterate through number of doors used
		for (int used_door = 1; used_door <= k; used_door++) {
			// Iterate through all possible positions to place this new door
			for (int i = 0; i < n; i++) {
				// partial_dist stores the sum of distance to fill rooms [i, j - 1]
				long long partial_dist = 0;
				/*
				 * Iterate through all possible placements of the last door and find the
				 * minimum if we use this placement with our new door at i
				 */
				for (int j = i + 1; j <= n; j++) {
					// Add the amount of distance needed to fill the new room at j - 1
					partial_dist += rooms[j - 1] * (j - i - 1);
					long long new_dist = dp[used_door - 1][j];
					if (new_dist < INT64_MAX) {
						new_dist += partial_dist;
					}
					dp[used_door][i] =
							min(dp[used_door][i], new_dist);
				}
			}
		}
		// Update the best answer using the current dp answer
		min_dist = min(min_dist, dp[k][0]);
		/*
		 * Put the first room to the end of the deque so that the first door would
		 * be placed at the second room
		 */
		int first_room = rooms.front();
		rooms.pop_front();
		rooms.push_back(first_room);
	}

	cout << min_dist << endl;
}
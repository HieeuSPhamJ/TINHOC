#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int dp[2][200001];

void dfs(int node = 1, int parent = 0) {
	int mx1 = 1, mx2 = 1;
	for (int i : graph[node]) if (i != parent) {
		dfs(i, node);
		if (dp[0][i] >= mx1) {
			mx2 = mx1;
			mx1 = dp[0][i];
		} else mx2 = max(mx2, dp[0][i]);
	}
	dp[0][node] = mx1 + graph[node].size() - 2;
	dp[1][node] = mx1 + mx2 + graph[node].size() - 3;
}

int main() {
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int leaves = 0;
	for (int i = 1; i <= n; i++) if (graph[i].size() == 1) leaves++;

	dfs();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (graph[i].size() > 1) ans = max(ans, max(dp[1][i], dp[0][i]) + 1);
	}
	// Check if the graph is a star to minus 1
	cout << ans - (leaves == n - 1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
const long long INF = (long long)300000 * 1000000000;
const long double EPS = 1e-3;

int n, k, a[N + 1];
pair<long double, int> dp[N + 1][2];

bool check(long double lambda) {
	dp[0][0] = {0, 0}, dp[0][1] = {-INF, 0};
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] =
		    max(make_pair(dp[i - 1][1].first + a[i], dp[i - 1][1].second),
		        make_pair(dp[i - 1][0].first + a[i] - lambda,
		                  dp[i - 1][0].second + 1));
	}
	return max(dp[n][0], dp[n][1]).second >= k;
};

int main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	long double lower = 0, upper = INF;
	while (lower + EPS < upper) {
		long double mid = (lower + upper) / 2;
		if (check(mid)) {
			lower = mid;
		} else {
			upper = mid;
		}
	}
	long double lambda = lower;
	check(lambda);
	printf("%lld\n",
	       (long long)round(lambda * k + max(dp[n][0], dp[n][1]).first));
}
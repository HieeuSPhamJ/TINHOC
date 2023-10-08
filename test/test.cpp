#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int mod = 123456789;
const int MAX_VAL = 1e5;

int n, m, k;
int id[MAX_VAL];
vector<int> maskList;
vector<vector<pii>> adj;

void add(int &a, const int& b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	if (n < m) swap(n, m);

	for (int mask = 0; mask < (1 << m); mask++) {
		bool ok = true;
		for (int i = 1; i < m; i++) {
			if ((mask >> i & 1) && (mask >> (i - 1) & 1)) {
				ok = false;
				break;
			}
		}
		if (ok && __builtin_popcount(mask) <= k) {
			id[mask] = maskList.size();
			maskList.pb(mask);
		}
	}

	for (int mask : maskList) {
		vector<pii> adjList;
		for (int nxtMask : maskList) {
			bool ok = true;
			for (int i = 0; i < m; i++) {
				if (mask >> i & 1) {
					if (nxtMask >> i & 1) {
						ok = false;
						break;
					}
					if (i - 1 >= 0 && (nxtMask >> (i - 1) & 1)) {
						ok = false;
						break;
					}
					if (i + 1 < m && (nxtMask >> (i + 1) & 1)) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				adjList.pb({id[nxtMask], __builtin_popcount(nxtMask)});
			}
		}
		adj.pb(adjList);
	}

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(maskList.size(), vector<int>(k + 1)));

	for (int j = 0; j < maskList.size(); j++) {
		add(dp[0][j][__builtin_popcount(maskList[j])], 1);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < maskList.size(); j++) {
			for (int z = 0; z <= k; z++) {
				for (pii nxt : adj[j]) {
					if (z + nxt.se <= k) {
						add(dp[i + 1][nxt.fi][z + nxt.se], dp[i][j][z]);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int j = 0; j < maskList.size(); j++) {
		add(ans, dp[n - 1][j][k]);
	}

	cout << ans;

	return 0;
}

/*


*/

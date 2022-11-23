#include <bits/stdc++.h>
 
using namespace std;

template<class A, class B>
    bool maximize(A& x, B y) {
        if (x < y) return x = y, true; else return false;
    }
    
template<class A, class B>
    bool minimize(A& x, B y) {
        if (x >= y) return x = y, true; else return false;
    }

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

#define     all(a)                a.begin(), a.end()
#define     fi                    first
#define     se                    second
//#define   int 	              long long

const int MAX_N = 1e5 + 5;
const int mod = 1e9 + 7; // 998244353

int n;
vector<int> adj[MAX_N];
int dp[MAX_N];
bool isLeaf[MAX_N];
int fact[MAX_N];
int iFact[MAX_N];

int fastPow(int a, int k) {
	int res = 1;
	while (k) {
		if (k & 1) {
			res = 1ll * res * a % mod;
		}
		a = 1ll * a * a % mod;
		k >>= 1;
	}
	return res;
}

int C(int k, int n) {
	if (k > n) {
		return 0;
	}
	return (1ll * (1ll * fact[n] * iFact[k] % mod) * iFact[n - k]) % mod;
}

void prepare(int u, int parent = 0) {
	int directChild = 0;
	for (int v : adj[u]) {
		if (v == parent) continue;
		prepare(v, u);
		directChild++;
	}

	if (!directChild) {
		dp[u] = 0;
		isLeaf[u] = true;
	}
}

void dfs(int u, int parent = 0) {
	if (dp[u] >= 0) return;

	int directChild = 0;
	int leafChild = 0;

	dp[u] = 1;

	for (int v : adj[u]) {
		if (v == parent) continue;
		dfs(v, u);
		dp[u] = 1ll * dp[u] * dp[v] % mod;
		directChild++;
		leafChild += isLeaf[v];
	}

	if (!leafChild) {
		if (!(directChild & 1)) {
			dp[u] = 0;
		}
		return;
	}

	for (int i = !(directChild & 1); i <= leafChild; i += 2) {
		(dp[u] += C(i, leafChild)) %= mod;
	}

	for (int v : adj[u]) {
		if (v == parent || isLeaf[v]) continue;
		dp[u] = 1ll * dp[u] * dp[v] % mod;
	}
}

signed main() {

    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// freopen("JUNGLE.INP", "r", stdin);
	// freopen("JUNGLE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
	}
	iFact[n] = fastPow(fact[n], mod - 2);
	for (int i = n - 1; ~i; i--) {
		iFact[i] = 1ll * iFact[i + 1] * (i + 1) % mod;
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
	}

	prepare(1);

	dfs(1);

	// for (int i = 1; i <= n; i++) {
	// 	cout << dp[i] << " ";
	// }
	cout << dp[1];

	return 0;
}

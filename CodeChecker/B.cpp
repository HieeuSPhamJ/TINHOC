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
//#define     int                   long long

const int MAX_N = 1.5e6 + 5;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[MAX_N][10];
vector<int> q[MAX_N];
int ans[MAX_N];
bool vis[MAX_N];

signed main() {
	
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int extra = n;
	int curr;

	for (int i = 1; i <= m; i++) {
		int x = i;
		vector<int> digit;
		while (x) {
			digit.push_back(x % 10);
			x /= 10;
		}
		reverse(all(digit));

		int u, v;
		cin >> u >> v;
		curr = u;
		for (int j = 0; j < (int) digit.size() - 1; j++) {
			++extra;
			adj[curr][digit[j]].push_back(extra);
			curr = extra;
		}
		adj[curr][digit.back()].push_back(v);
		curr = v;
		for (int j = 0; j < (int) digit.size() - 1; j++) {
			++extra;
			adj[curr][digit[j]].push_back(extra);
			curr = extra;
		}
		adj[curr][digit.back()].push_back(u);
	}

	int time = 1;
	q[0].push_back(1);
	vis[1] = true;
	for (int i = 0; i < time; i++) {
		for (int d = 0; d < 10; d++) {
			bool ok = false;
			for (int u : q[i]) {
				for (int v : adj[u][d]) {
					if (!vis[v]) {
						vis[v] = true;
						ok = true;
						ans[v] = (10ll * ans[u] + d) % mod;
						q[time].push_back(v);
					}
				}
			}
			time += ok;
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}

/*


*/
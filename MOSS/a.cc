#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

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

const int MAX_N = 3e5 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n;
int a[MAX_N];
int s[MAX_N];
int suff[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		
		suff[n + 1] = inf;
		for (int i = n; i; i--) {
			suff[i] = min(s[i], suff[i + 1]);
		}

		int ans = 0;
		int res = 0;
		for (int i = 0; i <= n; i++) {
			if (maximize(ans, s[n] + s[i] - suff[i + 1])) {
				res = s[i];
			}
		}

		cout << res << '\n';
	}

	return 0;
}

/*


*/
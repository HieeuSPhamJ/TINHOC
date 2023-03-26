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

const int MAX_N = 1e6 + 10;

bool isPrime[MAX_N];

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		int l, r;
		cin >> l >> r;

		for (int i = 0; i <= r - l + 1; i++) {
			isPrime[i] = true;
		}

		for (int i = 2; i * i <= r; i++) {
			for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
				isPrime[j - l] = false;
			}	
		}

		if (1 >= l) {
			isPrime[1 - l] = false;
		}

		int ans = 0;
		for (int i = 0; i <= r - l; i++) {
			ans += isPrime[i];
		}

		cout << ans << '\n';
	}	

	return 0;
}

/*


*/
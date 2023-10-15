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

const int MAX_N = 2e5 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n, k;
vector<int> primeDivisors;

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	// test n = 1

	int cnt2 = 0;
	int cnt3 = 0;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				if (i == 2 || i == 3) {
					cnt2 += (i == 2);
					cnt3 += (i == 3);
				}
				else {
					primeDivisors.pb(i);
					if (i >= 10) {
						cout << -1;
						exit(0);
					}
				}
				n /= i;
			}
		}
	}
	if (n != 1) {
		if (n == 2 || n == 3) {
			cnt2 += (n == 2);
			cnt3 += (n == 3);
		}
		else {
			primeDivisors.pb(n);
		}
		if (n >= 10) {
			cout << -1;
			exit(0);
		}
	}

	while (cnt2 >= 3) {
		primeDivisors.pb(8);
		cnt2 -= 3;
	}

	while (true) {
		if (cnt3 >= 2) {
			primeDivisors.pb(9);
			cnt3 -= 2;
			continue;
		}

		if (cnt3 >= 1 && cnt2 >= 1) {
			primeDivisors.pb(6);
			cnt3--;
			cnt2--;
			continue;
		}

		if (cnt2 >= 2) {
			primeDivisors.pb(4);
			cnt2 -= 2;
			continue;
		}

		break;
	}

	if (primeDivisors.size() + cnt2 + cnt3 > k) {
		cout << -1;
		exit(0);
	}

	while (cnt2 > 0) {
		primeDivisors.pb(2);
		cnt2--;
	}
	while (cnt3 > 0) {
		primeDivisors.pb(3);
		cnt3--;
	}

	while (primeDivisors.size() < k) {
		primeDivisors.pb(1);
	}

	sort(all(primeDivisors));
	for (int x : primeDivisors) {
		cout << x;
	}

	return 0;
}

/*


*/
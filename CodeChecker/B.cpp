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

const int MAX_N = 3e3 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n;
int a[MAX_N][MAX_N];
pii downRight[MAX_N][MAX_N], downLeft[MAX_N][MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= n; j++) {
				a[i][j] = s[j - 1] - '0';
				downLeft[i][j] = downRight[i][j] = {0, 0};
			}
		}


		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				sum += downLeft[i][j].fi + downRight[i][j].fi;
				(a[i][j] += sum) %= 2;
				if (a[i][j]) {
					ans++;
					downLeft[i + 1][max(1ll, j - 1)].se = true;
					downLeft[i + 1][max(1ll, j - 1)].fi++;
					downRight[i + 1][min(n + 1, j + 2)].se = true;
					downRight[i + 1][min(n + 1, j + 2)].fi--;
				}
				if (downRight[i][j].se) {
					downRight[i + 1][min(n + 1, j + 1)].se = true;
					downRight[i + 1][min(n + 1, j + 1)].fi += downRight[i][j].fi;
				}
				if (downLeft[i][j].se) {
					downLeft[i + 1][max(1ll, j - 1)].se = true;
					downLeft[i + 1][max(1ll, j - 1)].fi += downLeft[i][j].fi;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

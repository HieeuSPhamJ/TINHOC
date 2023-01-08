#include <bits/stdc++.h>
 
using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x >= y) return x = y, true; else return false;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << " ]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define     deb(x...)             cerr << "[ in " <<__func__<< "() : line " <<__LINE__<< " ] : [ " << #x << " ] = [ "; _print(x); cerr << '\n';

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
#define     pb(a)                 push_back(a)
#define     fi                    first
#define     se                    second
// #define     int                   long long

const int MAX_N = 2e5 + 5;
const int mod = 1e9 + 7; // 998244353
const int base = 256;

int n;
string s;
int POW[MAX_N];
int HASH[MAX_N];

int getHash(int l, int r) {
	return (1ll * HASH[r] - 1ll * HASH[l - 1] * POW[r - l + 1] + 1ll * mod * mod) % mod;
}

unordered_map<int, bool> m;
bool check(int len) {
	m.clear();
	for (int i = len; i <= n; i++) {
		int curr = getHash(i - len + 1, i);
		if (m[curr]) {
			return true;
		}
		m[curr] = true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);

	cin >> n;
	cin >> s;

	POW[0] = 1;
	for (int i = 1; i <= n; i++) {
		POW[i] = 1ll * POW[i - 1] * base % mod;
	}

	for (int i = 1; i <= n; i++) {
		HASH[i] = (1ll * HASH[i - 1] * base + s[i - 1] - 'a' + 1) % mod;
	}

	int low = 1;
	int high = n;
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}

/*


*/
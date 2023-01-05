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
const ll inf = 1e18 + 1;

int n;
int a[MAX_N];
bool mark[MAX_N];
int ans;
bool check;
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mark[i] = false;
		}

		ans = 0;
		check = false;
		for (int i = 1; i <= n; i++) {
			if (!mark[i]) {
				v.clear();
				int j = i;
				while (!mark[j]) {
					mark[j] = true;
					v.pb(j);
					j = a[j];
				}
				sort(all(v));
				for (int j = 0; j < (int) v.size() - 1; j++) {
					if (abs(v[j] - v[j + 1]) != 1) {
						continue;
					}
					check = true;
				}
				ans += v.size();
				ans--;
			}
		}

		cout << ans + (check ? -1 : 1) << '\n';
	}

	return 0;
}

/*


*/
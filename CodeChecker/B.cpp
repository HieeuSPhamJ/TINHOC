#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int n;
int a[10000];
int res;

// vector <ii> ls;

void backtrack(int tres){
	set <int> s[2];
	for (int i = 1; i <= n; i++){
		s[i % 2].insert(a[i]);
	}
	if (tres > n or (int)s[0].size() == 1 and (int)s[1].size() == 1){
		// if (res > tres){
		// 	cout << "====" << endl;
		// 	for (int i = 1; i <= n; i++){
		// 		cout << a[i] << " ";
		// 	}
		// 	cout << endl;
		// 	for (auto x: ls){
		// 		cout << x.fi << " " << x.se << endl;
		// 	}
		// }
		res = min(res, tres);
		return;
	}
	for (int i = 1; i <= n; i++){
		for (int c = 1; c <= n; c++){
			int old = a[i];
			if (a[i - 1] != c and a[i + 1] != c){
				a[i] = c;
				// ls.push_back({i,c});
				backtrack(tres + 1);
				a[i] = old;
				// ls.pop_back();
			}
		}
	}
}

signed main(){
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);
	//freopen("input.INP", "r", stdin);
	//freopen("output.OUT", "w", stdout);
	if (fopen(".inp", "r")) {
		freopen(".inp", "r", stdin);
		freopen(".out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	res = n - 1;
	backtrack(0);
	cout << res << endl;
	return 0;
}

/*
*/
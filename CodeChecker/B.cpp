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
int res = 0;

void backtrack(int id, int tres){
	if (id >= n){
		res = max(res,tres);
		return;
	}
	for (int i = id + 1, mi = 1e18, ma = 0; i <= n; i++){
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
		backtrack(i,tres + ma - mi);
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
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	backtrack(0,0);
	cout << res << endl;
	return 0;
}
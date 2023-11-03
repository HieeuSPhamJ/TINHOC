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

int a[110];

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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= 1; j--){
			map <int,int> cnt;
			int ok = 1;
			int sum = 0;
			for (int k = j; k <= i; k++){
				cnt[a[k]]++;
				sum += a[k];
			}
			for (auto i: cnt){
				if (i.se % 2){
					ok = 0;
				}
			}
			if (sum <= 0){
				ok = 0;
			}
			// if (ok){
			// 	cout << j << " " << i << endl;
			// }
			res += ok;
		}
	}
	cout << res << endl;
	return 0;
}
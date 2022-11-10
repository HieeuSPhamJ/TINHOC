#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e18;

int n, m, k;
int a[maxN];
int b[maxN];

int calLeq(int x) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = 1, high = m;
		int need = 0;
		if (a[i] == 0) {
			if (x >= 0) {
				ans += m;
			}
		}
		else {
			if (a[i] > 0) {
				while (left <= high) {
					int mid = (left + high) / 2;
					if (b[mid] * a[i] <= x) {
						need = mid;
						left = mid + 1;
					}
					else {
						high = mid - 1;
					}
				}
				ans += need;
			}
			else {
				need = m + 1;
				while (left <= high) {
					int mid = (left + high) / 2;
					if (b[mid] * a[i] <= x) {
						need = mid;
						high = mid - 1;
					}
					else {
						left = mid + 1;
					}	
				}
				ans += m - need + 1;
			}
		}
	}

	return ans;
}

signed main() {
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
	cin >> k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	sort(b + 1, b + m + 1);

	int left = -inf;
	int high = inf;
	int ans; 	

	while (left <= high) {
		int mid = (left + high) / 2;
		if (calLeq(mid) >= k) {
			ans = mid;
			high = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans;
	return 0;
}
#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

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
	int n, k, p;
	cin >> n >> k >> p;
	string s;
	cin >> s;
	int mask = 0;
	for (int i = 1; i <= n; i++){
		if (s[i - 1] == '1'){
			mask += (1 << (n - i));
		}
	}
	for (int cnt = -1;mask < (1 << n);mask++){
		int ok = 1;
		for (int i = 1; i <= p; i++){
			if (mask & (mask << i)){
				ok = 0;
			}
		}
		cnt+=ok;
        if (ok){
			// cout << bitset<5>(mask) << endl;
        }
		if (cnt == k){
			cout << bitset<20>(mask) << endl;
			return 0;
		}
	}
    cout << -1 << endl;
	return 0;
}
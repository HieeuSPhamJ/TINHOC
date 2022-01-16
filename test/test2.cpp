#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
 
int t;
int n;
bool check[51];
 
bool ktra() {
	for (int i = 1; i <= n; i++) {
		if ( !check[i] ) {
			return false;
		}
	}
	return true;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> t;
	while (t--) {
		cin >> n;
		memset(check, false, sizeof(check));
 
		for (int i = 1; i <= n; i++) {
			long long x;
			cin >> x;
			while ( x ) {
				if ( x <= n ) {
					if ( !check[x] ) {
						check[x] = true;
						break;
					}
				}
				x /= 2;
			}
		}
 
		cout << (ktra() ? "YES" : "NO" ) << "\n";
	}
 
	return 0;
}



#include <iostream>

using namespace std;

int n;

int main() {
	freopen( "CAPSO.INP", "r", stdin );
	freopen( "CAPSO.OUT", "w", stdout );
	
	long long b, d, a, c;
	cin >> n >> b >> d;
	a = b;
	c = d;
	if ( d > b ) {
		swap( b, d );
	}
	if ( a > c ) {
		swap( a, c );
	}
	for (int i = 2; i < n; i++) {
		long long inp;
		cin >> inp;
		if ( inp >= b ) {
			d = b;
			b = inp;
		}
		if ( inp <= a ) {
			c = a;
			a = inp;
		}
	}	
	cout << max( b * d, a * c );
	return 0;	
}
#include <iostream>
#include <stdio.h>

using namespace std;

int n;
long long a[1000006];
int f[1000006];

int main() {
	// freopen( "DAYLT.inp", "r", stdin );
	// freopen( "DAYLT.out", "w", stdout );

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int indexMax = 0;

	f[0] = 1;
	for (int i = 1; i < n; i++) {
		if ( a[i] > a[i - 1] ) {
			f[i] = f[i - 1] + 1;
		}
		else {
			f[i] = 1;
		}
		if ( f[i] > f[indexMax] ) {
			indexMax = i;
		}
	}

	for (int i = indexMax - f[indexMax] + 1; i <= indexMax; i++) {
		cout << i + 1 << " ";
	}

	return 0;
}
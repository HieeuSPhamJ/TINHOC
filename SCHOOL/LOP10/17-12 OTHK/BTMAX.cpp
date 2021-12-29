#include<bits/stdc++.h>
using namespace std;

int n, k;
long long a[1000007];

bool cmp( int a, int b){
    return (a > b);
}


int main() {
	freopen( "BTMAX.INP", "r", stdin );
	freopen( "BTMAX.OUT", "w", stdout );
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort( a + 1, a + n + 1, cmp);
	long long sum = a[1];
    // cout << sum << ' ';
	for (int i = 2; i <= k+1; i++) {
		sum += a[i];
        // cout << a[i] << ' ';
	}
    // cout << endl;
	for (int i = k+2; i <= n; i++) {
		sum -= a[i];
        // cout << a[i] << ' ';

	}
    // cout << endl;
	cout << sum;

	return 0;
}
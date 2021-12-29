#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000006];
int b[1000006];

int main() {
	freopen( "DAYSOLT.INP", "r", stdin );
	freopen( "DAYSOLT.OUT", "w", stdout );
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort( a + 1, a + n + 1);
	int index = 0;
	b[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if ( a[i] == a[j] + 1 and b[j] + 1 > b[i] ) {
				b[i] = b[j] + 1;
			}
		}
		if ( b[i] > b[index] ) {
			index = i;
		}
	}
	if ( b[index] < 1 ) {
		cout << -1;
		return 0;
	}
	int check = a[index - b[index]];
	cout << check << " ";
	for (int i = index - b[index]; i <= index; i++) {
		if ( a[i] == a[i - 1] + 1 ) {
			cout << a[i] << " ";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long Catalan(long long n) {
	long double ans = 1;
	for (int i = n + 2; i <= 2 * n; i++) {
		ans *= double(i) / double(i - n - 1);
	}
	return ans / n + 0.01;
}


int main(){
	long long n;
	cin >> n;
	cout << Catalan(n);
	return 0;
}
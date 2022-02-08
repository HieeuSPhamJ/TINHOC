#include<bits/stdc++.h>
using namespace std;


int main(){
	long long xa, ya, xb, yb, xc, yc, m, n;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	n = (xb - xa) / (xc -xa);
	m = (yb - ya) / (yc - ya);
	if (n == m){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}
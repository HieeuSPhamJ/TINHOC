#include<bits/stdc++.h>
using namespace std;

unsigned long long n;

unsigned long long Catalan(int n){
	long double ans=1;
	for (int i=n+2;i<=n+n;i++) {
		ans*=double(i)/double(i-n-1);
	}
	return ans/n+0.1;
}
int main() {
	freopen("VCATALAN.INP","r",stdin);
	freopen("VCATALAN.OUT","w",stdout);
	cin>>n;
	int count=1;
	while (Catalan(count)<n) {
		count++;
	}
	cout<<count;
	return 0;
}
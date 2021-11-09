#include<bits/stdc++.h>
using namespace std;


int main() {
	freopen("VFIBO.INP","r",stdin);
	freopen("VFIBO.OUT","w",stdout);
	unsigned long long n;
	cin>>n;
	unsigned long long a=0;
	unsigned long long b=1;
	unsigned long long count=0;
	while(a<n){
		int temp=a+b;
		a=b;
		b=temp;
		count++;
	}
	cout<<count;
	return 0;
}
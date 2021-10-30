#include <bits/stdc++.h>
using namespace std;

int main(){
	int i=4,n=2;
	int a=-(((double(i)-1)-(2*n/i))/2);
	int b=2*n/i-a;
	cout<<min(a,b)<<' '<<max(a,b);
	return 0;
}
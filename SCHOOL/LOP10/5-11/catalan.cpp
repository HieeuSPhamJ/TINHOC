#include<bits/stdc++.h>
using namespace std;

long long ezCata(long long n){
	if (n<=2) return 1; 
	else return ezCata(n-1)+ezCata(n-2);	
}

long long ulCata(long long n){
	double sqpi=sqrt(M_PI);
	return pow(4,n)/(pow(n,3/2)*sqpi);
	
}

int main(){
	int n;
	cin>>n;
	// cout<<ezCata(n);
	cout<<ulCata(n);
	return 0;
}
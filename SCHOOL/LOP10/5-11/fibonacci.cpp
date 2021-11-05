#include<bits/stdc++.h>
using namespace std;

long long ezFib(long long n){
	if (n<=2) return 1; 
	else return ezFib(n-1)+ezFib(n-2);
}

long long ulFib(long long n){
	double sq5=sqrt(5);
	return (1/sq5)*(pow(((1+sq5)/2),n))-(pow(((1-sq5)/2),n))+0.01;
	
}

int main(){
	int n;
	cin>>n;
	// cout<<ezFib(n);
	cout<<ulFib(n);
	return 0;
}
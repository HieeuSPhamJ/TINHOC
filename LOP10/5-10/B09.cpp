#include<bits/stdc++.h>
using namespace std;

void re(long long n){
	while(n>0){
		cout<<n%10;
		n/=10;
	}
}


int main(){
	long long n;
	cin>>n;
    re(n);
	return 0;
}
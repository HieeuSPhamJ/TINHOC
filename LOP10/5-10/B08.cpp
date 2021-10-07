#include<bits/stdc++.h>
using namespace std;

bool check(int n){
	if(n==1)
		return false;
    for (long long i=2;i*i<=n;i++){
    	if (n%i==0)
    	return false;
    }
    return true;
}


int main(){
	int n;
	cin>>n;
	// cout<<ans[n];
	if (check(n)) cout<<"LA SO NGUYEN TO";
	else cout<<"KHONG PHAI LA SO NGUYEN TO";
	return 0;
}
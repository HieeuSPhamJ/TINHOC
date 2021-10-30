#include<bits/stdc++.h>
using namespace std;

bool check(int n){
	if(n==1){
		// cout<<"NO";
    	return false;
    	}
    for (long long i=2;i*i<=n;i++){
    	if (n%i==0){
    	// cout<<"NO";
    	return false;
    	}
    }
    // cout<<"YES";
    return true;
}


int main(){
	int n;
	cin>>n;
	// cout<<ans[n];
	cout<<check(n);
	return 0;
}
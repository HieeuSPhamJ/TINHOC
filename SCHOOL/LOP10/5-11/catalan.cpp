#include<bits/stdc++.h>
using namespace std;


long long ulCata(unsigned int n){
    if (n<=1){
        return 1;
	}
    long long temp=0;
    for(int i=0;i<n;i++){
        temp+=ulCata(i)*ulCata(n-i-1);
	}
    return temp;
}
int main(){
	int n;
	cin>>n;
	// cout<<ezCata(n);
	cout<<ulCata(n);
	return 0;
}


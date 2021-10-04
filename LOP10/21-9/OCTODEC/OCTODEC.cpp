#include<bits/stdc++.h>
using namespace std;

long long power(int n){
	long long ans=1;
	for (int i=1;i<=n;i++)
		ans*=8;
	return ans;
}

long long Conv(string n){
	long long ans=0;
	int len = int(n.length())-1;
	for (int i=0;i<int(n.length());i++){
		ans+=(int(n[len--])-48)*power(i);
		
		// cout<<(int(n[len])-48)<<' '<<i<<endl;
		// cout<<len+1<<(int(n[len]))<<endl;
		// cout<<'@';
	}
	return ans;
}


int main(){
	freopen("OCTODEC.inp","r",stdin);
	freopen("OCTODEC.out","w",stdout);
    string n;
    cin>>n;
    cout<<Conv(n);
return 0;
}
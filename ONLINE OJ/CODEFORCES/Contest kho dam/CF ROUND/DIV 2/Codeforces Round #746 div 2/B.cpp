#include<bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin>>test;
	while(test--){
		int a;
		int n,x; cin>>n>>x;
		for (int i=1;i<=n;i++)  cin>>a;
		if (n>x) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
return 0;
}
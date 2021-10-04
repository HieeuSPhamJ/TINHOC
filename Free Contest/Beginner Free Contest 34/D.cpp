#include<bits/stdc++.h>
using namespace std;

int main(){
int test = 1;
cin>>test;
while(test--){
	int n = 5; 
	cin>>n;
	int a[10010];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	//for (int i=1;i<=n;i++) cout<<a[i];
	for (int i=1;i<=n;i++){
		int ans=0;
		//cout<<"# "<<i<<endl;
		for (int e=i-1;e>=1;e--){
			if (a[e]==a[i]) ans++;
			if (a[e]>a[i]) break;
		}
		for (int e=i+1;e<=n;e++){
			if (a[e]==a[i]) ans++;
			if (a[e]>a[i]) break;
		}
		cout<<ans<<' ';
	}
	cout<<endl;
}
	
return 0;
}
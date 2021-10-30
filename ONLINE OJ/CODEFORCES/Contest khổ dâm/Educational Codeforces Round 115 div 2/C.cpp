#include <bits/stdc++.h>
using namespace std;

int a[200010];
int count[200010];
map<int,int> check;

int main(){
int test; cin>>test;
while(test--){
	int n; cin>>n;
	double k=0;
	memset(count,0,sizeof(count));
	for (int i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
		check[i]=1;
	}
	k/=n;
	for (int i=1;i<=n;i++){
		if ()
	}
	
}
return 0;
}
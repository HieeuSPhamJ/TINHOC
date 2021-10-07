#include<bits/stdc++.h>
using namespace std;

int main(){
int test;
cin>>test;
while(test--){
	int n;
	cin>>n;
	int ans = 0;
	while(n--){
		int x,y;
		cin>>x>>y;
		ans = max(ans,x+y);
	}
	cout<<ans<<endl;
}
return 0;
}
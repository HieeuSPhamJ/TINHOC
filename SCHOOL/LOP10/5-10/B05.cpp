#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans1=0;
	int ans2=INT_MAX;
	while(n--) {
		int inp; cin>>inp;
		ans1=max(inp,ans1);
		ans2=min(inp,ans2);
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
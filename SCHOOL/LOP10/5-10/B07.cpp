#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans[3];
	memset(ans,0,sizeof(ans));
	while(n--) {
		int inp; cin>>inp;
		ans[inp%2]++;
		
	}
	cout<<ans[0]<<' '<<ans[1];
	return 0;
}
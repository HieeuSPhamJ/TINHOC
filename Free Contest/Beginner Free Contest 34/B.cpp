#include<bits/stdc++.h>
using namespace std;

int main(){
	string a[110][3];
	int ans[110];
	int n1,n2;
	memset(ans,0,sizeof(ans));
	cin>>n1;
	for (int i=1;i<=n1;i++) cin>>a[i][1]>>a[i][2];
	cin>>n2;
	for (int i=1;i<=n2;i++){
		string user,pass;
		cin>>user>>pass;
		for (int e=1;e<=n1;e++){
			if (a[e][1] == user and a[e][2] == pass ){
				ans[e]++;
				break;
			}
		}
	}
	for (int i=1;i<=n1;i++) cout<<ans[i]<<' ';
	
	

return 0;
}
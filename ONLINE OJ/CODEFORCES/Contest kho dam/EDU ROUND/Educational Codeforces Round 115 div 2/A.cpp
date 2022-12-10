#include <bits/stdc++.h>
using namespace std;


int main(){
int test; cin>>test;
while(test--){
	int n; cin>>n;
	string a1,a2;
	cin>>a1>>a2;
	// cout<<a1<<endl<<a2<<endl;	
	int check=0;
	for (int i=0;i<n;i++){
		// cout<<a1[i]<<' '<<a1[i]<<endl;
		if (a1[i]=='1' and a1[i]==a2[i]) {
			check=1;
			// break;
		}
	}
	if (check==0) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
return 0;
}
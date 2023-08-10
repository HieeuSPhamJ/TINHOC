#include<bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,h; cin>>n>>h;
		int m1=0,m2=0;
		for(int i=1;i<=n;i++){
			int inp; cin>>inp;
			if (inp>m1){
				m2=m1;
				m1=inp;
			}
			else m2=max(m2,inp);
			// cout<<inp<<m1<<m2<<endl;
		}
		
		int ans=h/(m1+m2);
		// cout<<ans<<' ';
		ans*=2;
		if (h%(m1+m2)==0) ans=ans;
		else if (h%(m1+m2)<=m1) ans++;
		else ans+=2;

		cout<<ans<<endl;
	}
return 0;
}
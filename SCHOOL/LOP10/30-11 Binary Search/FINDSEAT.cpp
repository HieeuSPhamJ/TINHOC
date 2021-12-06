#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("FINDSEAT.INP","r",stdin);
    freopen("FINDSEAT.OUT","w",stdout);
    long long n,m,t;
    cin>>n>>m>>t;
    // if (t/m+bool(t%m)<=n){
    //     cout<<t/m+bool(t%m)<<' '<<t%m;
    // }
    // else cout<<-1;
	if (t>n*m or t<1) {
		cout<<-1;
		return 0;
	}
	long long ans=!bool(t%m==0)+t/m;
	cout<<ans<<" "<<t-m*(ans-1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("TGPHANSO.inp","r",stdin);
	freopen("TGPHANSO.out","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<a/__gcd(a,b)<<' '<<b/__gcd(a,b);
	
	return 0;
}
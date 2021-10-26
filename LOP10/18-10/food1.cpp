#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("food1.inp","r",stdin);
	freopen("food1.out","w",stdout);
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	n-=z;
	cout<<(x+y)-n;
	return 0;
}

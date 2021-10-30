#include<bits/stdc++.h>
using namespace std;

int main(){
	double x[3],y[3];
	for (int i=0;i<=2;i++) cin>>x[i]>>y[i];
	double xab=x[1]-x[0];
	double yab=y[1]-y[0];
	double xac=x[2]-x[0];
	double yac=y[2]-y[0];
	if(xab*yac==xac*yab)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	return 0;
}

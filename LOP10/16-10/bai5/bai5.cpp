#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
	if (a>b) cout<<1;
	else if (b>c) cout<<2;
	else if (c>d) cout<<3;
	else if (d>a) cout<<4;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xepnhom.inp","r",stdin );
	freopen("xepnhom.out","w",stdout );
	long long m,n,k;
	cin>>m>>n>>k;
    int d=m+n-min(m/2,n)*3; 
    int x =(d>=k?0:(k-d)/3+((k-d)%3!=0));			
    cout<<min(n,m/2)-x;
	return 0;
}
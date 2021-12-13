#include<bits/stdc++.h>
using namespace std;

const int maxn=1e8;
long long n,A[maxn],Y;
long long m;


int main(){
	freopen("MARBLE.INP","r",stdin);
	freopen("MARBLE.OUT","w",stdout);
	cin>>n>>m;
	long long l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(A[i]>r){
			r=A[i];
		}
	}
	Y=(l+r)/2;
	while(l<r){
		int n2=0;
		for(int i=1;i<=m;i++){
			n2=n2+(A[i]+Y-1)/Y;
		}
		if(n2>n){
			l=Y+1;
		}
		else{
			r=Y;
		}
		Y=(l+r)/2;
	}
	cout<<Y;
	return 0;
}

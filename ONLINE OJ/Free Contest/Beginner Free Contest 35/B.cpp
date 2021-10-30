#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b,c; cin>>a>>b>>c;
		long long n1=abs(a+b*c);
	    long long n2=abs(a+b+c);
	    long long n3=abs(a-(b-c));
	    long long n4=abs(a+(b-c));
		long long n5=abs(a+b-c);
	    long long n6=abs(a-(b+c));
	    long long n7=abs(a*b*c);
	    long long n8=abs(a-b*c);
	    long long n9=abs(a*b-c);
	    long long n10=abs(a*b+c);
	    long long n11=abs(a-b+c);
	    long long n12=abs(a-b-c);
	    long long n13=abs(a+(b+c));
		cout<<min({n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13})<<endl;
	}
return 0;
}
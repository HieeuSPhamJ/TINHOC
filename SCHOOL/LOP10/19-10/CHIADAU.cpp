#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("CHIADAU.inp","r",stdin);
	// freopen("CHIADAU.out","w",stdout);
	int test;
	cin>>test;
	while(test--)
	{
		int a,b,d;
		cin>>a>>b>>d;
		if(abs(a-b)<=min(a,b)*d)
			cout<<"YES";
        else
			cout<<"NO";
		// bool ans=0;
		// if (a>b) swap(a,b);
		// ans+=((b/a-1+!(b%a==0))<=d);
		// if (ans==1) cout<<"YES";
		// else cout<<"NO";
		cout<<endl;
	}
	
	return 0;
}
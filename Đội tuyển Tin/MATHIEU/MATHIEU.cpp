#include <bits/stdc++.h>
using namespace std;

string s;
int a[200010];
int inp[200010];
int m;
char ans[200010];

int main(){
	freopen("MATHIEU.inp","r",stdin);
    freopen("MATHIEU.out","w",stdout);
	memset(inp,0,sizeof(inp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin,s);
	cin>>m;
	int k=s.length();
	for (int i=1;i<=m;i++){
		int n;
		cin>>n;
		inp[n]++;
	}
	// for (int i=1;i<=k;i++) cout<<inp[i];
	
	a[0]=inp[1];
	for (int i=2;i<=k;i++){
		a[i-1]=inp[i]+a[i-2];
	}
	
	// for (int i=0;i<k;i++) cout<<a[i];
	// cout<<endl<<'#'<<endl;
	// cout<<k/2;
	for (int i=0;i<(k+1)/2;i++){
		// cout<<s[k-i-1];
		if (a[i]%2==0){
			// cout<<0;
			// cout<<s[i];
			ans[i]=s[i];
			ans[k-i-1]=s[k-i-1];
		}
		else{
			// cout<<1;
			// cout<<s[k-i-1];
			ans[k-i-1]=s[i];
			ans[i]=s[k-i-1];
		}
	}
	// for (int i=0;i<k;i++) cout<<int(ans[i])<<' ';
	// cout<<endl;
	for (int i=0;i<k;i++) cout<<ans[i];
	// cout<<'|';

	
	return 0;
}
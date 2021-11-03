#include <bits/stdc++.h>
using namespace std;

long long n;
int ans[100000];

int main(){
	memset(ans,0,sizeof(ans));
	// freopen("SUMSEG.inp","r",stdin);
    // freopen("SUMSEG.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);r
	cin>>n;
	int e=1;
	for (long long i=1;i*i<=2*n;i++){
		if ((2*n)%i==0){
			// double a=-(((double(i)-1)-(2*n/i))/2);
			// double b=2*n/i-a;
			long long a=-(((double(i)-1)-(2*n/i))/2);
			long long b=2*n/i-a;
			a=min(a,b);
			b=max(a,b);
			// if (b!=n and a!=n and (long long)(a)==a and (long long)(b)==b){
			if (b!=n and a!=n and ((2*n/i)+i)%2==1){
				// cout<<i<<endl;
				// if (a==0) a=1;
				// if (b==0) b=1;
				// cout<<int(a)<<' '<<int(b)<<endl;
				ans[e++]=int(b);
				ans[e++]=int(a);
			}
		}
	}

	for (int i=e-1;i>=1;i--){
		cout<<ans[i]<<' ';
		if (i%2==1) cout<<endl;
	}


	return 0;
}

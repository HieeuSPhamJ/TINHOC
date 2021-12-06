#include <bits/stdc++.h>
using namespace std;

long long a[1000006];

int main() {
    freopen("SUM1.INP","r",stdin);
	freopen("SUM1.OUT","w",stdout);
    int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int inp;
			cin>>inp;
			a[i-j+n-1]+=inp;
		}
	}
	long long ans=a[1];
	for (int i=1;i<2*n;i++) {
		ans=max(ans,a[i]);
	}
	cout<<ans;

	return 0;
}
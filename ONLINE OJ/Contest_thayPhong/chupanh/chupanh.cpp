#include <bits/stdc++.h>
using namespace std;
int a[100010][6];
int b[100010];

bool cmp(int ax,int bx){
	int ans = 0;
	for (int i=1;i<=5;i++)
		ans += (a[ax][i] < a[bx][i]);
	return (ans>2);
}

int main(){
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n; cin>>n;
	for (int e=1;e<=5;e++)
		for (int i=1;i<=n;i++){
			int inp;
			cin>>inp;
			a[inp][e]+=i;
			b[i]=inp;
	}
	// cout<<'#';
	// for (int i=1;i<=n;i++) cout<<i<<' ';
	// cout<<endl;
	// for (int e=1;e<=5;e++){
		// cout<<'@';
		// for (int i=1;i<=n;i++)
			// cout<<a[i][e]<<' ';
		// cout<<endl;
	// }
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++) cout<<b[i]<<' ';
	
return 0;
}
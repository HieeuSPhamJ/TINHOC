#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	int ans = (a[1][2]-a[2][3]+a[1][3])/2;
	cout<<ans<<' ';
	for (int i=2;i<=n;i++) cout<<a[1][i]-ans<<' ';
	
    return 0;
}
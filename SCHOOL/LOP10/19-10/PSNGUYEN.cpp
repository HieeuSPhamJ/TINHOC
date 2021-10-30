#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("PSNGUYEN.inp","r",stdin);
	freopen("PSNGUYEN.out","w",stdout);
	int n,m;
    cin>>m>>n;
    int ans=0;
    for (int i=1;i<=min(m,n);i++){
        if (!((m+i)%(n+i))) ans++;
    }
    cout<<ans;
	return 0;
}
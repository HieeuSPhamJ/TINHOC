#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];

bool cmp(int a,int b){
	return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(b,0,sizeof(b));
    int m,n,k;
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m,cmp);
    for (int i=1;i<=m;i++){
    	b[i]=a[i]+b[i-1];
    	//cout<<a[i]<<' '<<' '<< b[i-1];
    }
    int ans = 0;
    for (int i=1;i+n-1<=m;i++){
    	if (a[i]-a[i+n-1]<=k){
    		ans = max(ans,b[i-1]-b[i+n-2]);
    		//cout<<i<<' '<<i+n<<endl;
    	}
    	cout<<'@'<<i<<' '<<i+n-1<<endl;
    	cout<<'*'<<b[i]<<' '<<b[i+n-2]<<endl;
    }
    // if (ans > 0 )
    	cout<<ans;
    // else cout<<-2;
    return 0;
}
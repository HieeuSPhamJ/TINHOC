#include <bits/stdc++.h>
using namespace std;

int inp[100010];
int a[100010];
int b[100010];
vector<int> ans;

bool cmp(int ax,int bx){
	return ax>bx;
}

int main() {
	freopen("SNOWMAN.inp","r",stdin);
    freopen("SNOWMAN.out","w",stdout);
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>inp[i];
    sort(inp+1,inp+n+1);
    fill(b+1,b+n+1,1);
    inp[0]=-1;
    int e=0;
    for (int i=1;i<=n;i++){
    	if (inp[i]!=inp[i-1]) a[++e]=inp[i];
    	else b[e]++;
    }
    
    int i=1;
    while (i<=e-2){
    	int j=i+1;
    	int k=j+1;
    	while (b[i]==0) i++;
		while (b[j]==0 or j<=i) j++;
		while (b[k]==0 or k<=j) k++;
		if (j>e) break;
    	while (b[i]>0 and b[j]>0 and b[k]>0){
    		ans.push_back(a[k]);
    		ans.push_back(a[j]);
    		ans.push_back(a[i]);
    		// cout<<a[k]<<' '<<a[j]<<' '<<a[i]<<endl;
    		// cout<<'@'<<k<<' '<<j<<' '<<i<<endl;
    		// cout<<'#'<<k<<' '<<j<<' '<<i<<endl;
    		// for (int x=1;x<=e;x++) cout<<a[x]<<' '<<b[x]<<endl;
    		b[k]--; b[j]--; b[i]--;
    	}
    }
    cout<<int(ans.size())/3<<endl;
	int count=1;
	for(auto x:ans){
		cout<<x<<' ';
		if (count%3==0) cout<<endl;
		count++;
	}
    
    
    return 0;
}

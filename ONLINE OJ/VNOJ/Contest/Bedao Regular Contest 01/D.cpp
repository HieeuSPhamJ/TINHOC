#include <bits/stdc++.h>
using namespace std;

// int a[1010][50010];
map <int,map<int,int>> a;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,t; cin>>m>>t;
    for(int i=1;i<=m;i++){
    	int n; cin>>n;
    	int check[n];
    	memset(check,0,sizeof(check));
    	for(int e=1;e<=n;e++){
    		int inp; cin>>inp;
    		if (check==0)
    			a[i][inp]=0;
    		a[i][inp]++;
    		// cout<<inp<<endl;

    	}
    }
    // for(int i=1;i<=m;i++){
    	// for(int e=1;e<=10;e++) cout<<a[i][e]<<' ';
    	// cout<<endl;
    // }
    while(t--){
    	int q; cin>>q;
    	int ans=0;
    	int count=0;
    	for (int i=1;i<=m;i++){
    		// cout<<a[i][q];
    		if (a[i][q]>0){
    			count++;
    		}
    		else count=0;
    		ans=max(ans,count);
    	}
    	cout<<ans<<endl;
    }

    
    return 0;
}
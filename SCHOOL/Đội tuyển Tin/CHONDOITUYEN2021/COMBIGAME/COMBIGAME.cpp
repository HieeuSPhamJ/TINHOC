#include <bits/stdc++.h>
using namespace std;

int a[1010][3];
int b[1010];

bool cmp(int ax,int bx){
	return ax>bx;
}

int main() {
	freopen("COMBIGAME.inp","r",stdin);
	freopen("COMBIGAME.out","w",stdout);
    int n; cin>>n;
    int e1=0,e2=0;
    for (int i=1;i<=n;i++){
    	int inp1,inp2; cin>>inp1>>inp2;
    	if (inp2>0){
    		e1++;
    		a[e1][1]=inp1;
    		a[e1][2]=inp2;
    		// cout<<'!'<<a[e1][1]<<a[e1][2]<<endl;
		}
		else{
			e2++;
    		b[e2]=inp1;
    		// cout<<'!'<<b[e2]<<endl;
		}
    }
    int ans=0,count=0;
    for (int i=1;i<=e1;i++){
    	// cout<<a[i][1]<<' '<<a[i][2]<<endl;
    	ans+=a[i][1];
    	count+=a[i][2];
    }
    // cout<<'#'<<endl;
    sort(b+1,b+1+e2,cmp);
    for (int i=1;i<=count;i++){
    	// cout<<b[i]<<endl;
    	ans+=b[i];
    }
    if (count==0) ans+=b[1];
    cout<<ans;
    
    
    
    
    
    
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int ans[1000000];

int main() {
    freopen("COINS.inp","r",stdin);
    freopen("COINS.out","w",stdout);
    int n;
    cin>>n;
	ans[0]=n;
    int e = 1;
    for (int i=n;i>=1;i--){
    	if (ans[e-1]%i==0){
    		ans[e]=i;
    		e++;
    	}
    }
    cout<<e-1<<endl;
    for (int i=1;i<e;i++) cout<<ans[i]<<' ';

    return 0;
}

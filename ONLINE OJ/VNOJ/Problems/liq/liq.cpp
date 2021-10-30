#include<bits/stdc++.h>
using namespace std;



int main(){
    int n; cin>>n;
    int a[1010];
    int b[1010];
    int ans = 0;
    a[0] = 0;
    b[0] = 0;
    for (int i = 1;i <= n;i++) cin>>a[i];
    
    for (int i = 1;i <= n;i++){
    	for (int j = i-1;j >= 0;j--){
    		cout<<i<<' '<<j<<' ';
    		if (a[i] > a[j]){
    			cout<<"check"<<endl;
    			b[i] = b[j]+1;
    			ans = max(ans,b[i]);
    			break;
    		}
    		cout<<endl;
    	}
    }
    cout<<ans;
return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    int ans=1410065408;
    for(int i=1;i<=n;i++){
    	int inp; cin>>inp;
    	ans=min(ans,inp);
    }
    cout<<ans;
    
    return 0;
}
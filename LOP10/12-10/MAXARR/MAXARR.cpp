#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        int inp; cin>>inp;
        ans=max(ans,inp);
    }
    cout<<ans;
return 0;
}
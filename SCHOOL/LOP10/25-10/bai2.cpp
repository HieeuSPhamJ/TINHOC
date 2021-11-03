#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout);
    long long m,n,k; cin>>m>>n>>k;
    ostringstream str;   
    str<<n*m*k;   
    string ans=str.str();
    // cout<<ans;
    if (int(ans.length())>=2 and ans[int(ans.length())-1]=='0'){
         cout<<"Yes";
    }
    else {
        cout<<"No";
    }
    return 0;
}
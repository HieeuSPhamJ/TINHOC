#include<bits/stdc++.h>
using namespace std;

int a[1003];


int main(){
    freopen("TUCLN.INP","r",stdin);
    freopen("TUCLN.OUT","w",stdout);
    int n;
    cin>>n;
    int ans;
    cin>>ans;
    n--;
    while(n--){
        int inp;
        cin>>inp;
        ans=__gcd(inp,ans);
    }
    cout<<ans;
    return 0;
}
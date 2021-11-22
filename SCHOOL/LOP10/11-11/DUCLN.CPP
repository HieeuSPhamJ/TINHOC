#include<bits/stdc++.h>
using namespace std;

// int a[1003];


int main(){
    freopen("DUCLN.INP","r",stdin);
    freopen("DUCLN.OUT","w",stdout);
    int n;
    cin>>n;
    int ans;
    cin>>ans;
    for (int i=2;i<=n;i++){
        int inp;
        cin>>inp;
        ans=__gcd(ans,inp);
    }
    cout<<ans;
    return 0;
}
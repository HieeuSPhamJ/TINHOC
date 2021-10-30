#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hopdiem.inp","r",stdin);
    freopen("hopdiem.out","w",stdout);
    double a,b,c;
    cin>>a>>b>>c;
    double r=sqrt((a*a+b*b));
    // cout<<r;
    if (c<=r) cout<<"Yes";
    else cout<<"No";    
    return 0;
}
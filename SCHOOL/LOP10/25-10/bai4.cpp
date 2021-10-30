#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("bai4.inp","r",stdin);
    freopen("bai4.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int n=max({a,b,c,d});
    int m=min({a,b,c,d});
    cout<<n/__gcd(n,m)<<" / "<<m/__gcd(n,m);
    return 0;
}
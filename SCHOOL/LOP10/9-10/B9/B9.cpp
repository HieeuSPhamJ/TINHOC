#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("B9.inp","r",stdin);
    freopen("B9.out","w",stdout);
    double a,b; cin>>a>>b;
    cout<<(a+b+abs(a-b))/2;
    return 0;
}
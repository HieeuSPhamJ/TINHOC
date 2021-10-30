#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("socola.inp","r",stdin);
    freopen("socola.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    if (a*b>=c and (c%a==0 or c%b==0)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("Kangaroos.inp","r",stdin);
    freopen("Kangaroos.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(b-a,c-b)-1;
    return 0;
}
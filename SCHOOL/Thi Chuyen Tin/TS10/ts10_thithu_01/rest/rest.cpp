#include<bits/stdc++.h>
using namespace std;

int main (){
freopen("rest.inp","r",stdin);
freopen("rest.out","w",stdout);
int t;
cin>>t;
for (int i=1;i<=t;i++){
    int a,b;
    cin>>a>>b;
    int c=__gcd(a,b);
    cout<<(a/c)*(b/c)<<endl;

}
return 0;
}

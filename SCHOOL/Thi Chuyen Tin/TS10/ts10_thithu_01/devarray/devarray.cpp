#include<bits/stdc++.h>
using namespace std;

int main (){
freopen("devarray.inp","r",stdin);
freopen("devarray.out","w",stdout);
int n,test;
cin>>n>>test;
int mi=1e9,ma=0;
for (int i=1;i<=n;i++) {
    int a;
    cin>>a;
    mi=min(a,mi);
    ma=max(a,ma);
}
for (int t=1;t<=test;t++){
    int q;
    cin>>q;
    if (q>=mi and q<=ma) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

return 0;
}

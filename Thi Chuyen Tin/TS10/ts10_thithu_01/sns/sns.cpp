#include<bits/stdc++.h>
using namespace std;

int main(){
//freopen("sns.inp","r",stdin);
//freopen("sns.out","w",stdout);
int t;
cin>>t;
long long mod=1e9+7;
for (int i=1;i<=t;i++){
    long long n;
    cin>>n;
    cout<<(n%mod)*(n%mod)%mod<<endl;
}

return 0;
}

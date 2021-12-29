#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("DEMBOI.INP","r",stdin);
    freopen("DEMBOI.OUT","w",stdout);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int count=0;
    for (int i=1;i<=n;i++){
        if (!(i%a)+!(i%b)+!(i%c)==2){
            count++;
            // cout<<i;
        }
    }
    cout<<count;
    return 0;
}
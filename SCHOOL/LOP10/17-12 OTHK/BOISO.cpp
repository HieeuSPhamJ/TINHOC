#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("BOISO.INP","r",stdin);
    freopen("BOISO.OUT","w",stdout);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int count=0;
    for (int i=1;i<=n;i++){
        if (!(i%a) and !(i%b) and !(i%c)){
            cout<<i<<' ';
            count++;
        }
    }
    if (count==0){
        cout<<-1;
    }
    return 0;
}
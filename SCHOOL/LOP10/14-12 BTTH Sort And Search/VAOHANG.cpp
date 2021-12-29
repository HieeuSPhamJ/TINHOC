#include<bits/stdc++.h>
using namespace std;

int x[1000006];
int y[1000006];

int main(){
    freopen("VAOHANG.INP","r",stdin);
    freopen("VAOHANG.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    for (int i=1;i<=n;i++){
        cin>>y[i];
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,abs(x[i]-y[i]));
    }
    cout<<ans;
    return 0;
}
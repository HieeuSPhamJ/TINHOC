#include<bits/stdc++.h>
using namespace std;
#define MM 1000000010
int n,m;
int a[100010];


int main(){
    freopen("buygifts.inp","r",stdin);
    freopen("buygifts.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=MM;
    for (int i=1;i<=n-m;i++){
        ans=min(ans,a[i+m-1]-a[i]);
    }
    cout<<ans;
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,m,n;
    int a[5*10000];
    cin>>k>>m>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int ans=1000000000;
    while(m--){
        //cout<<'#'<<m<<endl;
        sort(a+1,a+n+1);
        ans = min(a[n]-a[1],ans);
        a[1]+=k;
        a[n]-=k;
        //for (int i=1;i<=n;i++)
        //    cout<<a[i]<<endl;
    }
    sort(a+1,a+n+1);
    ans = min(a[n]-a[1],ans);
    cout<<ans;

return 0;
}

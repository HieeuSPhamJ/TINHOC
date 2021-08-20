#include<bits/stdc++.h>
using namespace std;

int t[60010];
int r[60010];
int ans[60010];
int main(){
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=n-1;i++) cin>>r[i];
    ans[1]=t[1]; ans[2]=min(t[1]+t[2],r[1]);
    for (int i=3; i<=n; i++)
        ans[i]=min(t[i]+ans[i-1],r[i-1]+ans[i-2]);
    cout<<ans[n];
return 0;
}

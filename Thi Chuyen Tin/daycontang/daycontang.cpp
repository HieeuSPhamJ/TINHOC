#include<bits/stdc++.h>
using namespace std;

int n,m=0,ans=0,a[1000],b[1000],tr[1000];

int main(){
    fill(tr+1,tr+n+1,0);
    fill(b+1,b+n+1,1);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    for (int i=1;i<=n;i++){
        int mb=0;
        for (int j=i-1;j>=1;j--)
        if (a[i]>a[j]){
            if (b[j]>mb){
                mb=b[j];
                tr[i]=j;
            }
        }
        b[i]=mb+1;
    }
    for (int i=1;i<=n;i++){
        ans=max(b[i],ans);
    }
    //for (int i=1;i<=n;i++){
    //    if (b[i]=ans)tr[ans+1]=i;
   // }
    int vt=n;
    cout<<ans<<endl<<a[vt];
    while (vt>0){
        vt=tr[vt];
        cout<<' '<<a[vt];
    }
    return 0;
}

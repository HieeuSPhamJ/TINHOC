#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    int a[100010];
    memset(a,0,sizeof(a));
    for (int i=1;i<=r/2;i++){
        //cout<<i<<endl;
        for (int e=2;e*i<=r;e++){
            a[e*i]+=i;
            //cout<<e*i<<' ';
        }
        //cout<<endl;
    }
    int ans=0;
    for (int i=l;i<=r;i++){
        //cout<<i<<'-'<<a[i]<<' ';
        ans+=a[i]>i;
    }
    cout<<endl<<ans;
return 0;
}

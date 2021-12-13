#include<bits/stdc++.h>
using namespace std;

long long a[10004];

int main(){
    freopen("vongltmax.inp","r",stdin);
    freopen("vongltmax.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=-(1e9+1);
    long long tempSum=0;
    int curDir=0;
    for (int i=1;i<=n;i++){
        if (tempSum+a[i]<=0){
            curDir=i-1;
        }
        tempSum=max(a[i],tempSum+a[i]);
        // cout<<tempSum<<' ';
        ans=max(ans,tempSum);
    }
    for (int i=1;i<=curDir;i++){
        tempSum=max(a[i],tempSum+a[i]);
        // cout<<tempSum<<' ';
        ans=max(ans,tempSum);
    }
    // cout<<endl<<curDir<<endl;
    cout<<ans;

    return 0;
}
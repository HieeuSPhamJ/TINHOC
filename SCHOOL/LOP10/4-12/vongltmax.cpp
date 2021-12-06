#include<bits/stdc++.h>
using namespace std;

long long a[10004];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    long long ans=-(1e9+1);
    long long tempSum=0;
    
    for (int i=1;i<=n;i++){
        tempSum=max(a[i],tempSum+a[i]);
        ans=max(ans,tempSum);
    }
    for (int i=1;i<=n;i++){
        tempSum=max(a[i],tempSum+a[i]);
        ans=max(ans,tempSum);
    }
    cout<<ans;

    return 0;
}
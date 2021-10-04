#include <bits/stdc++.h>
using namespace std;

int a[100000],b[100000];
int ans[1000000];

int main(){
int n,m;
cin>>n>>m;
for (int i=0;i<n;i=i+1) cin>>a[i];
for (int i=0;i<n;i=i+1) cin>>b[i];
int count=0;
for (int i=0;i<n;i=i+1)
    for (int j=0;j<n;j=j+1){
        ans[count]=a[i]+b[j];
        count=count+1;
    }
sort (ans,ans+count);
for (int l=0;l<m;l=l+1){
    cout<<ans[l]<<" ";
}
return 0;
}
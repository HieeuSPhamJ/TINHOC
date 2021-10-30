#include<bits/stdc++.h>
using namespace std;

int main (){
int n,k;
cin>>n>>k;
int a[100];
for (int i=1;i<=n;i++) cin>>a[i];
if (a[1]==0) {
    cout<<0;
    return 0;
}
k=a[k];
int s=0;
for (int i=1;i<=n;i++) if (a[i]>=k and a[i]!=0) s++;
cout<<s;
return 0;
}

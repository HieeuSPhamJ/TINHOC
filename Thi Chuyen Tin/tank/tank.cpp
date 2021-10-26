#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int main (){
int m,n;
cin>>m>>n;
b[0]=0;
for (int i=1;i<=n;i++) {
    cin>>a[i];
    b[i]=a[i]+b[i-1];
}
int s=0;
for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++)
        if (b[j]-b[i-1]<m and j-i+1>s) s=j-i+1;
cout<<s+1;
return 0;
}

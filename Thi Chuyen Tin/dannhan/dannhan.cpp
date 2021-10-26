#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int main(){
int n,s=0;
memset(b,0,sizeof(b));
cin>>n;
for (int i=1;i<=n;i++) {cin>>a[i]; b[a[i]]++;}
for (int i=1;i<=1000010;i++) if (b[i]>1) s+=(b[i]-1);
cout<<s;
return 0;
}

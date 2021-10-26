#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n;
int main(){
a[0]=1000000;
cin>>n;
for (int i=1;i<=n;i++) cin>>a[i];
sort (a+1,a+n+1);
int s=0;
for (int i=1;i<=n;i++){
    s+=min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
}
cout<<s;
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main (){
int n;
int a[1010];
cin>>n;
int s=0;
for (int i=1;i<=n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if (a+b+c>=2) s++;
}
cout<<s;
return 0;
}

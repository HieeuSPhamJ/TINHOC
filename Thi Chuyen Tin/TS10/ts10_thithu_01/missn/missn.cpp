#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("missn.inp","r",stdin);
freopen("missn.out","w",stdout);
int n;
cin>>n;
int a[200020];
for (int i=1;i<=n;i++){
    int inp;
    cin>>inp;
    a[inp]++;
}
cin>>n;
for (int i=1;i<=n;i++){
    int inp;
    cin>>inp;
    a[inp]--;
}
for (int i=1;i<=100010;i++){
    if (a[i]<0) cout<<i<<' ';
}

return 0;
}

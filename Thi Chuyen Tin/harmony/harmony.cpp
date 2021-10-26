#include<bits/stdc++.h>
using namespace std;

int main(){
//freopen("harmony.inp","r",stdin);
//freopen("harmony.out","w",stdout);
int test;
cin>>test;
for (int t=1;t<=test;t++){
    int n,a[1010],check=0;
     a[0]==2000;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        if (abs(a[i]-a[i-1])==1) check++;
        if (check>n/2) { cout<<"Yes"<<endl; break; }
    }
    if (check<=n/2) cout<<"No"<<endl;
}
return 0;
}

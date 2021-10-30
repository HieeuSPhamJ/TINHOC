#include<bits/stdc++.h>
using namespace std;
int t,n,a[1010],b[1010];

void dodaique(int n){
for (int i=1;i<=n;i++) cin>>a[i];
}
void demque (int n){
for (int i=1;i<=n;i++) b[a[i]]++;
}

int main(){
cin>>t;
for (int ti=1;ti<=t;ti++){
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    cin>>n;
    dodaique(n); demque(n);
    int x1=-1,x2=-1;
    for (int i=1010;i>=1;i--)
        if(b[i]>=2){
        x1=i; b[i]-=2; break;
    }
    for (int i=1010;i>=1;i--)
    if(b[i]>=2){
        x2=i; b[i]-=2; break;
    }
    if (x1>-1 and x2>-1) cout<<x1*x2;
    else cout<<-1;
}
return 0;
}

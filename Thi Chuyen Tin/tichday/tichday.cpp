#include<bits/stdc++.h>
using namespace std;
int d=0;
int x[100000010];
void phantich1(int n){
    for (int i=2;i*i<=n;i++)
     while(n%i==0){ x[i]++; d++; n/=i; }
    if (n!=1) x[n]++;
}
void phantich2(int n){
    for (int i=2;i*i<=n;i++)
     while(n%i==0){ x[i]--; d--; n/=i; if(x[i]>0){cout<<0;break;}}
    if (n!=1) x[n]--;
}
int main(){
memset(x,0,sizeof(x));
int t; cin>>t;
for (int test =1;test<=t;test++){
    int n,m,a,b;
    d=0;
    for (int i=1;i<=n;i++){
        cin>>a;
        phantich1(a);
    }
    for (int i=1;i<=n;i++){
        cin>>a;
        phantich2(b);
    }
    if (d!=0) cout<<1;
    else cout<<0;
}

return 0;
}

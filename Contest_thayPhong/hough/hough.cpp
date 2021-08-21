#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int b[100010];
int c[100010];
int main(){
  memset(a,0,sizeof(a));
  memset(c,0,sizeof(c));
  cin>>n>>m;
  for (int i=1;i<=n;i++){
    int inp;
    cin>>inp;
    a[inp]++;
  }
  for (int i=1;i<=m;i++) cin>>b[i];
  for (int i=1;i<=110;i++){
    c[i]=a[i]+c[i-1];
    //cout<<"c: "<<i<<' '<<c[i-1]<<','<<a[i]<<' ';
  }
  //cout<<endl;
  for (int i=1;i<=m;i++) cout<<c[b[i]]-a[b[i]]<<endl;


  return 0;
}

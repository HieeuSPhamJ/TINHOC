#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int b1[1000010];
int b2[1000010];
int main(){
  cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i];
  a[n+1]=0;
  b1[0]=0;
  b2[0]=0;
  int m1=0;
  int m2=0;
  int ans=1000010;
  for (int i=1;i<=n;i++){
    if (a[i]==1){
      m1++;
    }
    else{
      m2++;
    }
    b1[i]=m1;
    b2[i]=m2;
  }
  for (int i=0;i<=n;i++){
    ans=min(ans,b2[i]+b1[n]-b1[i]);
    //cout<<b2[i]+b1[n]-b1[i]<<' ';
  }
  //cout<<endl;
  cout<<ans;

  return 0;
}

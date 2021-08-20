#include <bits/stdc++.h>
using namespace std;
int n;
double a[100010];

int main(){
  cin>>n;
  int aver = 0;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    aver+=a[i];
  }
  sort(a+1,a+n+1);
  for (int i=2;i<=n;i++){
    a[i]=(a[i]+a[i-1])/2;
    //cout<<a[i]<<' ';
  }
  cout<<fixed<<setprecision(5)<<a[n]*n-aver;

  return 0;
}

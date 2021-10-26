#include <bits/stdc++.h>
using namespace std;
int a[100000100];

int main (){
  int n,m=0;
  cin>>n;
  for (int i=1;i<=n;i++) {
    int inp;
    cin>>inp;
    a[inp]++;
    m=max(m,inp);
  }
  int s=0;
  for (int i=1;i<=n;i++){
    //cout<<a[i];
    s+=(a[i]/2);
  }
  cout<<s*s;

  return 0;
}

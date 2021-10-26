#include<bits/stdc++.h>
using namespace std;

int main (){
  int n,p;
  cin>>n>>p;
  int ans=0;
  for (int i=1;i<=n;i++){
    if (__gcd(n,i)==p) ans++;
  }
  cout<<ans;
return 0;
}

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
  int ans=0;
  while (n>0){
    ans+=n%10;
    n=n/10;
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout<<solve(n);
return 0;
}

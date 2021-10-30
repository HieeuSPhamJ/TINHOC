#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  int ans = 0;
  int check[200];
  memset(check,0,sizeof(check));
  int last = 0;
  int sum = 0;
  int total = 0;
  for (int i=0;i<=n-1;i++){
    if (check[int(s[i])]==0){
      if (total == 1) last = i;
      total++;
      check[int(s[i])]=1;
    }
    if (total >= 2){
      ans = max(ans,i-last);
      memset(check,0,sizeof(check));
    }
  }

  cout<<ans;


  return 0;
}

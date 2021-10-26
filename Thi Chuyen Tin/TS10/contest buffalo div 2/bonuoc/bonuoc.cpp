#include<bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin>>n;
  int s=0;
  for (int i=1;i<=n;i++){
  if (n%i==0){
    int si=0;
    for (int e=1;e<=i;e++){
      if (i%e==0) si++;
      if (si>4) break;
    }
    if (si==4) s++;
  }
  }
  cout<<s;

}

#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[4],b[4];
  int s=0;
  for (int i=1;i<=3;i++) { cin>>a[i]; s+=a[i]; }
  for (int i=1;i<=3;i++) { cin>>b[i]; s+=b[i]; }
  int s0=s;
  for (int i=1;i<=3;i++)
    for (int e=1;e<=3;e++){
      s=min(s,(s0-a[i]-b[e]+abs(a[i]-b[e])));
    }
 cout<<s;
return 0;
}

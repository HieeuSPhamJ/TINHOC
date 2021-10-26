#include <bits/stdc++.h>
using namespace std;
int a[1010][3];
int b[1000010];
int c[1000010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2];
  int index=0;
  for (int i=1;i<=n;i++){
    for (int e=i;e<=n;e++){
      int x=abs(a[i][1]-a[e][1]);
      int y=abs(a[i][2]-a[e][2]);
      b[index]=sqrt(abs(x*x+y*y));
      //cout<<b[index]<<endl;
      index++;
    }
  }
  int ans=0;
  for (int i=1;i<=index;i++){
    c[b[i]]++;
    if (c[b[i]]==2 and b[i]!=0) {
      ans++;
      c[b[i]]=0;
    }
  }
  cout<<ans;
return 0;
}

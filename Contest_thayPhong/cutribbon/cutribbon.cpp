#include <bits/stdc++.h>
using namespace std;
int main(){
 int a,b,c,n;
 cin>>n>>a>>b>>c;
 int ans=0;
 for (int x=0;x<=4000;x++)
  for (int y=0;y<=4000;y++){
    int z=(n-x*a-y*b)/c;
    //if (z<0) break;
    if (abs(a*x)+abs(b*y)+abs(c*z)==n)
    ans=max(ans,x+y+z);
    //cout<<x<<' '<<y<<' '<<z<<endl;

  }
  cout<<ans;
 return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
double a,b,c,d;
cin>>a>>b>>c>>d;
double ans1=a/c-b/d;
double ans2=c/d-a/b;
double ans3=d/b-c/a;
double ans4=b/a-d/c;
double m=max(max(ans1,ans2),max(ans3,ans4));
if (ans1==m) cout<<0;
else if (ans2==m) cout<<1;
else if (ans3==m) cout<<2;
else cout<<3;
 return 0;
}

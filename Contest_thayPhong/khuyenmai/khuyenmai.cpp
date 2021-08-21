#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
cin>>a;
int n=a.length()-1;
if (a[0]=='1')
  for (int i=1;i<=n;i++){
    if (a[i]!='0'){
      a[i]='0';

      break;
    }
  }
else a[0]='1';

for (int i=0;i<=n;i++) cout<<a[i];


return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main (){
char a;
cin>>a;
string s;
cin>>s;
int ans=0;
for (int i=0;i<=s.length();i++){
  if (s[i]==a) ans++;
}
cout<<ans;
return 0;
}

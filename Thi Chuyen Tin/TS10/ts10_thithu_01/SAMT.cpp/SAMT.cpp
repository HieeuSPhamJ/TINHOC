#include<bits/stdc++.h>
using namespace std;

int main (){
  //freopen("input.inp","r",stdin);
  //freopen("output.out","w",stdout);
  double l;
  long double s1,s2;
  cin>>l>>s1>>s2;
  l=sqrt(2)*l;
  int t;
  cin>>t;
  while(t--){
    long double i;
    cin>>i;
    i=sqrt(2*i);
    cout<<abs( (i-l) / (s1-s2) )<<endl;
  }
  return 0;
}

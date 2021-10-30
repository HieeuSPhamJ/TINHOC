#include<bits/stdc++.h>
using namespace std;

int main (){
  int s=0,check;
  string a;
  cin>>a;
  for (int i=0;i<=9;i++){
    if (a[i]>=48 and a[i]<=57)
      s+=(int(a[i])-48)*(i+1);
    else
      check=i+1;
    //cout<<int(a[i])<<' '<<s<<endl;
  }
  //cout<<s;
  for (int i=0;1<=9;i++){
    if ((i*check+s)%11==0){
      cout<<i;
      break;
    }
  }
return 0;
}

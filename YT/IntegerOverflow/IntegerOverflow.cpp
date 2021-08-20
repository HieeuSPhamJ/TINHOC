#include<bits/stdc++.h>
using namespace std;

int absInteger (int i){
  if (i<0) return -i;
  else return i;
}

int main (){
  int i;
  cin>>i;
  cout<<"absInteger("<<i<<") = "<<absInteger(i);
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main (){
int test;
cin>>test;
while(test--){
  int n;
  cin>>n;
  int check=0;
  for (int i=1;i<=n;i++){
    if (n%i==0) check++;
  }
  //cout<<check;
    cout<<check%2<<endl;


}


return 0;
}

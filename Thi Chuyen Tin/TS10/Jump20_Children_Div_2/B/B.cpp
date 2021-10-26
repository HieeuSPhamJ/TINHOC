#include<bits/stdc++.h>
using namespace std;

int main (){
int test;
cin>>test;
while (test--){
  int n,k;
  cin>>n>>k;
  int check=1;
  cout<<max(1,n-k);
  while (n>0){
    if (check%2!=0) n=n-max(1,n-k);
    else n=n-1;
    check++;
  }
  n=n-max(1,n-k);
  //cout<<n<<' '<<k;
  n=n-1;
  //cout<<n<<' '<<k;
  //cout<<check%2<<endl;

}


return 0;
}

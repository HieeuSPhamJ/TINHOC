#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main (){
  int n;
  long long s=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>a[i];
    s+=a[i];
  }
  cout<<s/n<<' ';
  int l=0;
  for (int i=1;i<=n;i++){
    l+=abs(s/n-a[i]);
  }
  cout<<l;
return 0;
}

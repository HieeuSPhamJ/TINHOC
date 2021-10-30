#include<bits/stdc++.h>
using namespace std;

int main (){
int n,t;
cin>>n>>t;
int s=0;
while(t--){
    int l,r,k;
    cin>>l>>r>>k;
    s+=((r-l+1)*k);
}
    cout<<s/n;
return 0;
}

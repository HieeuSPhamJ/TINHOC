#include<bits/stdc++.h>
using namespace std;

int main (){
int t;
cin>>t;
while (t--){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    if (n%x<=2 and n%x==m%y) cout<<"Chefirnemo";
    else cout<<"Pofik";
    cout<<endl;
}


return 0;
}

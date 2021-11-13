#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,n;
    cin>>a>>b>>n;
    for (int i=1;i<=n;i++){
        int e=(n-a*i)/b;
        if (abs(i)==i and abs(e)==e and a*i+b*e==n and i>0 and e>0){
            cout<<i<<' '<<e<<endl;
        }
    }
    return 0;
}
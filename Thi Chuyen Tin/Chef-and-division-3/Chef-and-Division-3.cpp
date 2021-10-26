#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k,d,a;
    cin>>t;
    for (int test=1;test<=t;test++){
        //cout<<"test:"<<test<<endl;
        cin>>n>>k>>d;
        int s=0;
        for (int i=1;i<=n;i++){
            cin>>a; s+=a;
        }
        //cout<<s/k<<endl;
        if (s/k<=d) cout<<s/k<<endl;    else cout<<d<<endl;
    }
    return 0;
}

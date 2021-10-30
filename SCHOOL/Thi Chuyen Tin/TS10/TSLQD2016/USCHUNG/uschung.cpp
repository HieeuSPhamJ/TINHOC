#include <bits/stdc++.h>
using namespace std;
int m,n;


int main(){
    cin>>m>>n;
    int a=min(n,m);
    int b=max(n,m);
    for (int i=1;i<=a/2;i++){
        if (b%i==0 and a%i==0) cout<<i<<' ';
    }
    if (b%a==0) cout<<a;
return 0;
}

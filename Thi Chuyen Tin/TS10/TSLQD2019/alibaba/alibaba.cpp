#include<bits/stdc++.h>
using namespace std;

int main (){
    int n,d;
    cin>>n>>d;
    int a=(n/3)-d;
    if (3*a+3*d==n) cout<<a<<' '<<a+d<<' '<<a+d*2;
    else cout<<-1;
return 0;
}

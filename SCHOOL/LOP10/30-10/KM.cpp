#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("KM.inp","r",stdin);
    freopen("KM.out","w",stdout);
    int n,m;
    cin>>n>>m;
    double x=(n*m)/double(m+1);
    cout<<int(x+(int(x)!=x))*3;
    return 0;
}
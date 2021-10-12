#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("B4.inp","r",stdin);
    freopen("B4.out","w",stdout);
    double a,b,c;
    cin>>a>>b>>c;
    double p=(a+b+c)/2;
    cout<<fixed<<setprecision(2)<<"chu vi: "<<a+b+c<<' '<<"dien tich: "<<sqrt(p*(p-a)*(p-b)*(p-c));
    return 0;
}
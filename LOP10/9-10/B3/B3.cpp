#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<fixed<<setprecision(2)<<sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return 0;
}
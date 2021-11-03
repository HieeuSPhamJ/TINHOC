#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("tugiac.inp","r",stdin);
    freopen("tugiac.out","w",stdout);
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if (abs(x1-x2)==abs(y1-y2)){
        cout<<"HINHVUONG"<<endl;
        double r=abs(x1-x2)/2;
        cout<<fixed<<setprecision(4)<<M_PI*r*r;
    }
    else{
        cout<<"HINHCHUNHAT"<<endl;
        double r=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/2;
        cout<<fixed<<setprecision(4)<<M_PI*r*r;
    }
    return 0;
}
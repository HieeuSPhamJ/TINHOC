#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double d=b*b-4*a*c;
    // cout<<d<<endl;
    if(d<0){
        cout<<-1;
        return 0;
    }
    if (!d){
        cout<<fixed<<setprecision(5)<<-b/(2*a);
        return 0;
    }
    cout<<fixed<<setprecision(5)<<(-b-sqrt(d))/(2*a)<<' '<<(-b+sqrt(d))/(2*a);
return 0;
}
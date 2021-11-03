#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("BAUCU.inp","r",stdin);
    freopen("BAUCU.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b or b==c or a==c){
        cout<<"BAU LAI";
    }
    else {
        if (a>b and a>c){
            cout<<"An";
        }
        else if (b>c and b>a){
            cout<<"Vinh";
        }
        else cout<<"Quang";

    }
    return 0;
}
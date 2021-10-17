#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }   
    cout<<b;
    return 0;
}
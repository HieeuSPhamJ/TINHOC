#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("VFIBO.INP","r",stdin);
    freopen("VFIBO.OUT","w",stdout);
    long long n;
    cin>>n;
    long long a=1;
    long long b=1;
    for (int i=3;1;i++){
        long long temp=b;
        b+=a;
        a=temp;
        if (b==n){
            cout<<i;
            break;
        }
        if (b>n){
            cout<<-1;
            break;
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        if (floor(sqrt(n))*floor(sqrt(n))==n){
            cout<<1;
        }
        else{
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
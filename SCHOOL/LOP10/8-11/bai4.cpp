#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    n++;
    long long ans=1;
    while (n-- and n>0){
        // cout<<n;
        ans*=n;
    }
    cout<<ans;
    return 0;
}
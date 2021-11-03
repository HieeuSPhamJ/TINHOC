#include<bits/stdc++.h>
using namespace std;

long long power(int n){
    long long ans=1;
    for (int i=1;i<=n;i++)
        ans*=2;
    return ans;
}

int main(){
    // cout<<0%2;
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        long long zero=0;
        long long one=0;
        for (int i=1;i<=n;i++){
            int inp;
            cin>>inp;
            if (inp==0) zero++;
            if (inp==1) one++;
        }
        // cout<<one<<' '<<zero<<endl;
        cout<<one*power(zero)<<endl;
    }

    return 0;
}
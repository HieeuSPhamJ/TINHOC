#include<bits/stdc++.h>
using namespace std;

bool check(unsigned long long n){
    if (n <= 1){
        return 0;
    }
    for (unsigned long long i = 2; i * i <=n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}



unsigned long long Fib(unsigned long long n){
    unsigned long long count=0;
    unsigned long long a=1;
    unsigned long long b=1;
    for (unsigned long long i=1;i<=n;i++){
        unsigned long long temp=a;
        a+=b;
        b=temp;
        if (check(a)){
            // cout<<a<<' ';
            count++;
        }
        // cout<<a<<endl;
    }
    
    return count;
}

int main(){
    freopen("NFIBO.INP","r",stdin);
    freopen("NFIBO.OUT","w",stdout);
    unsigned long long n;
    cin>>n;
    cout<<Fib(n);
    return 0;
}
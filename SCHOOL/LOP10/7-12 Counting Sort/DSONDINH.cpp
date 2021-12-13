#include<bits/stdc++.h>
using namespace std;

long long calNum(long long n){
    long long ans=0;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

long long cal(long long n){
    long long ans=0;
    for (long long i=1;i*i<=n;i++){
        if (n%i==0){
            ans+=calNum(i);
            if (n/i!=i){
                ans+=calNum(n/i);
            }
        }
    }
    return ans;
}

int main(){
    freopen("DSONDINH.INP","r",stdin);
    freopen("DSONDINH.OUT","w",stdout);
    long long n;
    cin>>n;
    // cout<<cal(10);
    long long tempAns=n;
    for (int i=1;i<=100000;i++){
        if (tempAns==cal(tempAns)){
            cout<<i;
            return 0;
        }
        else tempAns=cal(tempAns);

    }
    cout<<-1;
    return 0;
}
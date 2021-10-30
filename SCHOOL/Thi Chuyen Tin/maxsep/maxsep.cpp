#include<bits/stdc++.h>
using namespace std;

int x[40010],mod=1e9+7;

void phantich(int n){
    for (int i=2;i*i<=n;i++)
        while(n%i==0){x[i]++; n/=i; }
    if (n!=1) x[n]++;
}
long long power(long long i,int x){
if (x==0) return 1;
if (x==1) return i;;
    return (i*power(i,x-1))%mod;
}
int main(){
    memset(x,0,sizeof(x));
    int n,k=40010;
    cin>>n;
    for (int i=2;i<=n;i++) phantich(i);
    long long rest=1;
    for (long long i=1;i<=k;i++){
        if (x[i]%2!=0) x[i]--;
        if (x[i]>=0){
            rest=((rest%mod)*power(i,x[i]))%mod;
        }
    }
    cout<<rest;
    //cout<<power(n,9);
    return 0;
}

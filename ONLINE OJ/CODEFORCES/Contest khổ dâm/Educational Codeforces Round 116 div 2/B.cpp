#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n,k;
        cin>>n>>k;
        long long count=0;
        long long temp=1;
        while(n>0){
            n-=temp;
            count++;
            temp*=2;
            // cout<<n<<' '<<count<<' '<<temp<<endl;
            if (temp>k){
                n=n+temp-k;
                break;
            }
        }
        cout<<n;
        // cout<<count+(n/k)+(n%k==0);
        cout<<endl;
    }
}
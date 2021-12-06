#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n;
    cin>>n;
    long long count=0;
    for (long long i=1;i<=n;i++){
        for (long long e=1;e*i<=n;e++){
            long long j=n/(i*e);
            // for (long long j=1;i*e*j<=n;j++){
                // cout<<i<<' '<<e<<' '<<j<<endl;
                count+=j;
            // }
        }
    }
    cout<<count;
return 0;
}
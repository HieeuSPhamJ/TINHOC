#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        if (n%2==0) {
            long long int r=n/2;
            cout<<(n+1)*r<<endl;
        }
        else{
            long long int k=(n+1)/2;
            cout<<-(n*k);
        }
        cout<<endl;

    }
return 0;
}

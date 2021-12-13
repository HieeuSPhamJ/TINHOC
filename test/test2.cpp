#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if (n==1){
        cout<<"NO";
        return 0;
    }
    for (int i=2;i*i<=n;i++){
        if (!(n%i)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
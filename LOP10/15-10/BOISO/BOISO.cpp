#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    cin>>a>>n;
    for (int i=1;i*a<=n;i++){
        cout<<i*a<<' ';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<' '; 
    }
    return 0;
}
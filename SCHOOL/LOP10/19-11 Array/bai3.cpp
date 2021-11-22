#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    int n;
    long long k;
    cin>>n>>k;
    int count=0;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
    }
    for (int i=1;i<=n;i++){
        if (a[i]==k){
            count++;
        }
    }
    cout<<count;
    return 0;
}
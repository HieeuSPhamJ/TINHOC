#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+10;

int a[maxN];


int main(){
    freopen("MINK.INP","r",stdin);
    freopen("MINK.OUT","w",stdout);
    int n,k;
    cin>>n>>k;
    for  (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[k];
    return 0;
}
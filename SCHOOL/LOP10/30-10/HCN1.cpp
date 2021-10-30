#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("HCN1.inp","r",stdin);
    freopen("HCN1.out","w",stdout);
    int a[4];
    for (int i=0;i<4;i++){
        cin>>a[i];
    }
    sort(a,a+4);
    cout<<a[0]*a[2];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    freopen("tkx2.inp","r",stdin);
    freopen("tkx2.out","w",stdout);
    int n;
    long long x;
    cin>>n>>x;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        if (a[i]>x){
            cout<<a[i];
            break;
        }
    }
    return 0;
}
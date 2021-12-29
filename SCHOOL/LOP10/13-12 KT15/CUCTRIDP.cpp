#include<bits/stdc++.h>
using namespace std;

int a[1000006];

int main(){
    freopen("CUCTRIDP.INP","r",stdin);
    freopen("CUCTRIDP.OUT","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int count=0;
    for(int i=2;i<n;i++){
        if (a[i]>a[i-1] and a[i]>a[i+1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}

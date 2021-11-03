#include<bits/stdc++.h>
using namespace std;

int a[2000006];
int b[2000006];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int inp; cin>>inp;
        a[i+n]=a[i]=inp;
    }
    b[0]=0;
    for (int i=1;i<n*2;i++){
        b[i]=b[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        
    }

    return 0;

}
#include<bits/stdc++.h>
using namespace std;

long long c[2001][2001];

int main(){
    freopen("TOPHOP.INP","r",stdin);
    freopen("TOPHOP.OUT","w",stdout);
    int n,k;
    cin>>n>>k;
    // long long factor=1;
    // long long factorn=1;
    // long long factork=1;
    // long long factorkn=1;
    // for (int i=1;i<=n;i++){
    //    factor*=i;
    //    if (i==n) factorn=factor;
    //    if (i==k) factork=factor;
    //    if (i==n-k) factorkn=factor;
    // }
    // cout<<factorn/(factork*factorkn);

    for (int i=0;i<=n;i++){
        c[i][0]=1;
        c[i][i]=1;
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    // for (int i=2;i<=n;i++) {
    //     for (int j=1;j<i;j++) {
    //         c[i][j]=c[i-1][j-1]+c[i-1][j];
    //     }
    // }
    cout<<c[n][k];

return 0;
}


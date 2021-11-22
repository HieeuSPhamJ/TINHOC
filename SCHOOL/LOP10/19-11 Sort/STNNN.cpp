#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+10;


int a[maxN];

int main(){
    freopen("STNNN.INP","r",stdin);
    freopen("STNNN.OUT","w",stdout);
    int n;
    cin>>n;
    for  (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=-1;
    a[n+1]=-2;
    for (int i=1;i<=n+1;i++){
        if (abs(a[i]-a[i-1])>1){
            cout<<a[i-1]+1;
            break;
        }
    }
    return 0;
}
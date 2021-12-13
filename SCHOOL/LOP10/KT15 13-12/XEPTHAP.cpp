#include<bits/stdc++.h>
using namespace std;

int a[1004];

int main(){
    freopen("XEPTHAP.INP","r",stdin);
    freopen("XEPTHAP.OUT","w",stdout);
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        a[inp]++;
    }
    int maxans=0;
    int countans=0;
    for(int i=1;i<=1004;i++){
        countans+=(a[i]>0);
        maxans=max(maxans,a[i]);
    }
    cout<<maxans<<' '<<countans;
    return 0;
}

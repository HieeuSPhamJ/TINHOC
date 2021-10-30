#include<bits/stdc++.h>
using namespace std;
int n;
char a[2000010];

int main(){
    freopen("xeptao.inp","r",stdin);
    freopen("xeptao.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n*2;i++) cin>>a[i];
    int d0=0,d1=0;
    for (int i=2;i<=n*2;i++){
        if (a[i]==a[i-1] and a[i]=='0') {
            d0++;
        }
    }

    for (int i=2;i<=n*2;i++){
        if (a[i]==a[i-1] and a[i]=='1') {
            d1++;
        }

    }
    cout<<max(d1,d0);
    //cout<<d0<<' '<<d1;
return 0;
}

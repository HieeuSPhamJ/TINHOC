#include<bits/stdc++.h>
#define M 200010
using namespace std;

int n,k;
int no;
int a[M];
int ChiPhi=0;

int main(){
    freopen("replacesum.inp","r",stdin);
    freopen("replacesum.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n>>k; no=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while (n>1){
        int sum=0;
        int i=1;
        for (;i<=min(k,n);i++) sum+=a[i];
        ChiPhi+=a[min(k,n)]-a[1];
        for (int e=k+1;e<=n;e++){
            a[e-k]=a[e];
        }
        n=n-min(k,n);
        i=n;
        while (a[i]>sum and i>0){
            a[i+1]=a[i];
            i--;
        }
        a[++i]=sum;
        n++;
        //for(int e=1;e<=n;e++) cout<<a[e]<<' ';
        //cout<<endl<<ChiPhi<<' '<<sum<<endl;
    }
    cout<<a[1]<<endl<<ChiPhi;
return 0;
}

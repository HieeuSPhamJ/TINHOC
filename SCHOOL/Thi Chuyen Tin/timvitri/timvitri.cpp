#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];

int timkiem(int l,int r,int m){
    cout<<l<<" "<<r<<endl;
if (l>r) return 0;
if (a[m]<k) return timkiem(m+1,r,(m+1+r)/2);
if (a[m]>k) return timkiem(l,m-1,(l+m-1)/2);
else{
    if (a[m-1]<k) return m;
    return timkiem(l,m-1,(l+m-1)/2);
}
}

int main(){
    srand(time(0));
    n=20;
    a[0]=-1;
    for(int i=1;i<=n;i++) a[i]=a[i-1]+rand()%3;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    //for (int i=1;i<=n;i++)     cin>>a[i];
    cin>>k;
    cout<<timkiem(1,n,(1+n)/2);
return 0;
}

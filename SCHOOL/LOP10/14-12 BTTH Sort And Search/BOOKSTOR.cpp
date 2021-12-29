#include<bits/stdc++.h>
using namespace std;

int a[1000006];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("BOOKSTOR.INP","r",stdin);
    freopen("BOOKSTOR.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long ans=0;
    for (int i=1;i<=n;i+=3){
        ans+=a[i]+a[i+1];
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    freopen("tongltk.inp","r",stdin);
    freopen("tongltk.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
    }
    long long resultMax=0;
    long long tempMax=0;
    int count=0;
    for (int i=1;i<=n;i++){
        // cout<<resultMax<<' '<<tempMax<<endl;
        count++;
        tempMax+=a[i];
        resultMax=max(resultMax,tempMax);
        if (count>=k){
            tempMax-=a[i-k+1];
            count--;
            // cout<<'@';
            // cout<<i;
        }
    }
    cout<<resultMax;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    freopen("tongltmax.inp","r",stdin);
    freopen("tongltmax.out","w",stdout);
    int n;
    cin>>n;
    int check=0;
    long long maxNum=-(long long)(1e10+10);
    cout<<maxNum;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
        check=((a[i]>0) or (check));
        maxNum=max(maxNum,a[i]);
    }
    if (!check){
        cout<<maxNum;
    }
    else{
        long long resultMax=0;
        long long tempMax=0;
        for (int i=1;i<=n;i++){
            // cout<<resultMax<<' '<<tempMax<<endl;
            tempMax+=a[i];
            if (tempMax<0){
                tempMax=0;
            }
            resultMax=max(resultMax,tempMax);
        }
        cout<<resultMax;
    }

    return 0;
}
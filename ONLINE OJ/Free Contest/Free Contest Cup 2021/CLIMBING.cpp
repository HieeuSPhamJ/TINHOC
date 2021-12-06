#include<bits/stdc++.h>
using namespace std;

const int maxN=1000006;


int a[maxN];



int main(){
    int n,m,c;
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n-m+1;i++){
        int minA=a[i];
        int maxA=a[i];
        for (int e=i+1;e<i+m;e++){
            minA=min(minA,a[e]);
            maxA=max(maxA,a[e]);
        }
        // cout<<endl;
        // cout<<minA<<' '<<maxA<<endl;
        if (abs(maxA-minA)<=c){
            cout<<i<<endl;
        }
        // cout<<i<<endl;
    }
    return 0;
}
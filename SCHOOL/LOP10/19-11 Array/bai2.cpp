#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];


int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxIndex=0;
    long long maxNum=a[1];
    for (int i=1;i<=n;i++){
        if (a[i]>=maxNum){
            maxNum=a[i];
            maxIndex=i;
        }
    }
    cout<<maxIndex;
    return 0;
}
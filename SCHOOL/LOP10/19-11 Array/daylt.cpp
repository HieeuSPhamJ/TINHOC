#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

long long a[maxN];
long long dp[maxN];

// void check(int index){
//     int achec=0;
//         index+=achec;
// }



int main(){
    freopen("daylt.inp","r",stdin);
    freopen("daylt.out","w",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i]; 
    }
    int checkIndex=0;
    int maxIndex=0;
    dp[1]=1;
    for(int i=1;i<n;i++){
        // maxIndex=max(maxIndex,checkIndex);
        if (a[i]>a[i-1]){
            dp[i]=dp[i-1]+1;
            // check(1);
        }
        else{
            dp[i]=1;
            // check(2);
        }
        if(dp[i]>dp[checkIndex]){
            checkIndex=i;
            // check(3);
        }
    }
    for (int i=1+checkIndex-dp[checkIndex];i<=checkIndex;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
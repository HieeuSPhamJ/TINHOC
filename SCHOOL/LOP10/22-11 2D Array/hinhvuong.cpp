#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int e=1;e<=m;i++){
            int inp;
            cin>>inp;
            dp[i][e]=inp+dp[i-1][e]+dp[i][e-1]+dp[i-1][e-1];
        }
    }
    for (int i=1+k;i<=n;i++){
        
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int main(){
    freopen("hinhvuong.inp","r",stdin);
    freopen("hinhvuong.out","w",stdout);
    
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int e=1;e<=m;e++){
            int inp;
            cin>>inp;
            dp[0][e]=0;
            dp[i][0]=0;
            dp[i][e]=inp+dp[i-1][e]+dp[i][e-1]-dp[i-1][e-1];
        }
    }
    for (int i=1+k;i<=n;i++){
        for (int e=1+k;e<=m;e++){
            if (dp[i][e]-dp[i-k][e]-dp[i][e-k]+dp[i-k][e-k]==k*k){
                cout<<i-k+1<<' '<<e-k+1;
                return 0;
            }
            // cout<<dp[i][e]<<' ';
        }
        // cout<<endl;
    }
    cout<<-1;
    return 0;
}
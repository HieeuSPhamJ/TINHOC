#include<bits/stdc++.h>
using namespace std;
#define long long long
const long N=2e3+10;
const long oo=1e18;
long m,dp[N][N],A[N],n,sum[N];
void cnp(long l,long r,long optl,long optr,long g){
    if(l>r || optr<optl) return;
    long mid=(l+r)>>1;
    long best=oo;
    long opt=optl;
    for(long j=optl; j<=min(mid+1,optr); j++){
        if(best>=dp[j][g-1]+(sum[mid]-sum[j])*(mid-j)){
            best=dp[j][g-1]+(sum[mid]-sum[j])*(mid-j);
            opt=j;
        }
    }
    dp[mid][g]=best;
    cnp(l,mid-1,optl,opt,g);
    cnp(mid+1,r,opt,optr,g);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("aquarium.inp","r",stdin);
    freopen("aquarium.out","w",stdout);
    cin>>n>>m;
    for(long i=1; i<=n; i++){
        cin>>A[i];
    }
    sort(A+1,A+n+1);
    for(long i=1; i<=n; i++){
          sum[i]=sum[i-1]+A[i];
    }
    for(long i=1; i<=n; i++){
        for(long j=1; j<=m; j++){
            dp[i][j]=oo;
        }
    }
     for(long i=1; i<=n; i++){
        dp[i][1]=sum[i]*i;
    //    cout<<dp[i][1]<<' ';
    }
    for(long k=2; k<=m; k++){
        cnp(1,n,1,n,k);
    }
    cout<<dp[n][m];
    return 0;
}

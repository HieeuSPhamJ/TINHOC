#include<bits/stdc++.h>
using namespace std;
#define long long long
const long N=5e3+7;
long n,q,x,y,A[N][N],S[N][N],cnt,a,b,c,d;
string s;
stack<long> ds;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("RECTCNT.inp","r",stdin);
    freopen("RECTCNT.out","w",stdout);
    cin>>n>>q;
    for(long i=1; i<=n; i++){
        cin>>s;
        for(long j=0; j<n; j++){
            A[i][j+1]=s[j]-'0';
        }
    }
    for(long i=1; i<=n; i++){
        for(long j=1; j<=n; j++){
            S[i][j]=A[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
        }
    }
    for(long i=1; i<=n; i++){
        for(long j=1; j<=n; j++){
            for(long k=i; k>=1; k--){
                if(S[i][j]-S[k-1][j]-S[i][j-1]+S[k-1][j-1]!=0) break;
                for(long z=j; z>=1; z--){
                   if(S[i][j]-S[k-1][j]-S[i][z-1]+S[k-1][z-1]!=0) break;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<'\n';
    while(q--){
        cin>>x>>y;
        A[x][y]^=1;
        cnt=0;
    for(long i=1; i<=n; i++){
        for(long j=1; j<=n; j++){
            S[i][j]=A[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
        }
    }
    for(long i=1; i<=n; i++){
        for(long j=1; j<=n; j++){
            for(long k=i; k>=1; k--){
                if(S[i][j]-S[k-1][j]-S[i][j-1]+S[k-1][j-1]!=0) break;
                for(long z=j; z>=1; z--){
                   if(S[i][j]-S[k-1][j]-S[i][z-1]+S[k-1][z-1]!=0) break;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<'\n';
    }
    return 0;
}

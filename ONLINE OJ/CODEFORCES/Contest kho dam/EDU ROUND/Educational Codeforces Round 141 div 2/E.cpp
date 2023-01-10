#include<bits/stdc++.h>
using namespace std;
#define long long long
#define ll pair<long,long>
#define st first
#define nd second
const long N=5e5+10;
long n,l,r,mid,A[N],t,m,ans,B[N],s,ma[N],sum[N],mi[N],pos,z;
bool check(long a){
    if(a<=pos) return true;
    if(a==pos+1 && s-z+A[a]<=m) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(long i=1; i<=n; i++) {cin>>A[i]; sum[i]=A[i]+sum[i-1]; ma[i]=max(ma[i-1],A[i]); B[i]=A[i];}
        sort(B+1,B+n+1);
        pos=0;
        s=0;
        z=0;
        for(long i=1; i<=n; i++) if(s+B[i]<=m) {z=max(z,B[i]); s+=B[i]; pos=i;} else break;
        mi[n]=A[n];
        for(long i=n-1; i>=1; i--){
            mi[i]=min(mi[i+1],A[i]);
        }
        ans=0;
        for(long i=1; i<=n; i++){
            if(check(i)){
                ans=i;
            }
        }
        cout<<(n-ans+1)<<'\n';
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define long long long
const long m=(1<<8);
const long N=2e5+10;
long l,r,mid,ans,n,A[N],d,F[(1<<8)],t,gt;
void update(long a,long val){
    for(; a<m; a+=a&(-a)) F[a]+=val;
}
long get(long a){
    long t=0;
    for(; a>=1; a-=a&(-a)) t+=F[a];
    return t;
}
long xuly(long pos){
    l=1;
    r=201;
    long f;
    while(l<=r){
        mid=(l+r)>>1;
        if(get(mid)>=pos){
            f=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return f;
}
int main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>d;
    for(long i=1; i<=n; i++){
        cin>>A[i];
        A[i]++;
    }
    for(long i=1; i<=d; i++){
        update(A[i],1);
    }
    for(long i=d+1; i<=n; i++){
        gt=xuly((d+1)/2)-1;
        if(d&1) gt*=2;
        else gt+=xuly((d+2)/2)-1;
        if(gt<=A[i]) ans++;
        update(A[i-d],-1);
        update(A[i],1);
    }
    cout<<ans;



    return 0;
}
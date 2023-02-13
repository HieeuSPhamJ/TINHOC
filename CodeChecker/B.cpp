#include<bits/stdc++.h>
using namespace std;

#define long long long
const long N=1e5+10;
const long Bit=(1<<17);
long q,n,D[N*4],x,y,F[Bit+10],H[N],ans1,S[N],type,d,sz[N],lazy[N*4],cnt;
vector<long> ds[N];
void DFS(long a,long p){
    for(long v: ds[a]){
        if(v!=p){
            cnt++;
            H[v]=H[a]+1;
            S[v]=cnt;
            sz[v]=S[v];
            DFS(v,a);
            if(a!=1) sz[a]=max(S[a],sz[v]);
        }
    }
}
void day(long id){
    long t=lazy[id];

    lazy[id*2]+=t;
    D[id*2]+=t;

    lazy[id*2+1]+=t;
    D[id*2+1]+=t;

    lazy[id]=0;
}
long get(long id,long l,long r,long pos){
    if(l>pos || r<pos) return 0;
    if(l==r){
        return D[id];
    }
    day(id);
    long mid=(l+r)>>1;
    return get(id*2,l,mid,pos)+get(id*2+1,mid+1,r,pos);
}
long getb(long a){
    long sl=0;
    for(; a<=Bit; a+=a&(-a)) sl+=F[a];
    return sl;
}
void updateb(long a,long val){
    for(; a>=1; a-=a&(-a)) F[a]+=val;
}
void update(long id,long l,long r,long u,long v,long val){
    if(v<u) return;
    if(u>r || l>v) return;
    if(u<=l && r<=v){
        D[id]+=val;
        lazy[id]+=val;
        return;
    }
    day(id);
    long mid=(l+r)>>1;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    D[id]=D[id*2]+D[id*2+1];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>n>>q;
    for(long i=1; i<n; i++){
        cin>>x>>y;
        ds[x].push_back(y);
        ds[y].push_back(x);
    }
    DFS(1,1);
    while(q--){
        cin>>type;
        if(type==1){
            cin>>x;
            if(x==1) cout<<ans1<<'\n';
            else cout<<get(1,1,cnt,S[x])+getb(H[x])<<'\n';
        }
        else{
            cin>>y>>x>>d;
            if(y==1){
                updateb(d,x);
                ans1+=x;
                continue;
            }
            if(S[y]+d>sz[y]){
                update(1,1,cnt,S[y],sz[y],x);
              //  cout<<S[y]<<' '<<sz[y]<<'\n';
            }
            else{
                update(1,1,cnt,S[y],S[y]+d,x);
            }
            if(d>=H[y]){
                update(1,1,cnt,S[y]-H[y]+1,S[y]-1,x);
                d-=H[y];
                ans1+=x;
                if(!d) continue;
                update(1,1,cnt,S[y]-H[y]+1,min(S[y]-H[y]+d,sz[y]),-x);
               // cout<<d<<'\n';
                updateb(d,x);
            }
            else update(1,1,cnt,S[y]-d,S[y]-1,x);
        }
    }



    return 0;
}
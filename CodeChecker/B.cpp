#include <bits/stdc++.h>
#define Mine {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ii pair <long long,long long>
#define lli long long
#define se second
#define fi first
#define li long
using namespace std;

const int N=1e5+5;
int n,m;
lli A[N],B[N];

lli GetMaxXor(int n,lli b){
    lli max=0,mask=0,Val;
    set<ii> mSet;
    for (int i=30;i>=0;i--){
        mask|=(1<<i);
        for (int j=0;j<n;++j){
            mSet.insert({A[j]&mask,A[j]});
        }
        lli newMax=max|(1<<i);
        for (ii prefix:mSet){
            if((newMax^prefix.fi)==(b&mask)){
                max=newMax;
                Val=prefix.se;
                break;
            }
        }
        mSet.clear();
    }
    return Val;
}

int main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    // freopen("E.INP","r",stdin);
    // freopen("E.OUT","w",stdout);
    Mine;
    cin>>n;
    for(int i=0;i<n;++i) cin>>A[i];
    int Size=sizeof(A)/sizeof(A[1]);
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>B[i];
        cout<<GetMaxXor(Size,B[i])<<" ";
    }
    return 0;
}
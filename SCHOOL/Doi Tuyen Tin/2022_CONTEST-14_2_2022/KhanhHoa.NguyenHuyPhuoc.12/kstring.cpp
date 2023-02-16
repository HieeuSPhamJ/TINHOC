#include<bits/stdc++.h>
using namespace std;
#define long long long
const long mod=7e6+3;
const long N=5e4+10;
long n,k,d,so,s2,val,ans,T[N][2],pos,p2;
string s;
long ds[mod+2],ds2[mod+2];
long base[2]={52,73};
vector<long> sz;
vector<long> sz2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("kstring.inp","r",stdin);
    freopen("kstring.out","w",stdout);

    cin>>n>>d;
    cin>>s;
    if(d==1){
        cout<<n*(n-1)/2<<' ';
        pos=2;
    }
    else pos=1;
    p2=1;
    for(long k=pos; k<=n/2; k++){
        sz.clear();
        sz2.clear();
        ans=0;
        for(long i=k; i<=n; i+=k){
            so=0;
            for(long j=i-k+1; j<=i; j++){
                if(!d){
                    so=(so*base[0]+(s[j-1]-'a'+2))%mod;
                }
                else{
                    so=(so*base[0]+(s[j-1]-'a'+2))%mod;
                    T[j][0]=so;
                }
            }
            if(d){
                ans-=ds2[so]*(k-1);
                ds2[so]++;
                sz2.push_back(so);
                so=0;
                for(long j=i; j>=(i-k+1); j--){
                    so=(so*base[1]+(s[j-1]-'a'+2))%mod;
                    T[j][1]=so;
                }
                for(long j=(i-k+1); j<=i; j++){
                    so=1;
                    if(j==(i-k+1)){
                        so=(so*base[1] +T[j+1][1])%mod;
                        ans+=ds[so];
                        sz.push_back(so);
                    }
                    else if(j==i){
                        so=(T[j-1][0]*base[1]+so)%mod;
                        ans+=ds[so];
                        sz.push_back(so);
                    }
                    else{
                        so=(T[j-1][0]*base[1]+so)%mod;
                        so=(so*base[1]+T[j+1][1])%mod;
                        ans+=ds[so];
                        sz.push_back(so);
                    }
                    ds[so]++;
                }
            }
            else{
                ans+=ds[so];
                ds[so]++;
                sz.push_back(so);
            }
        }
        for(long v: sz) ds[v]=0;
        for(long v: sz2) ds2[v]=0;
            cout<<ans<<' ';
            if(!ans) {p2=k+1; }
            if(k==n/2) p2=n/2+1;
    }
    for(long k=p2; k<=n; k++){
        cout<<0<<' ';
    }





    return 0;
}

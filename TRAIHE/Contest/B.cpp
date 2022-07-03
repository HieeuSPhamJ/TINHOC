**
    <=================================================================>
    {     *Author:Le Son-Tk2cht                                       }
    {     *Spawn:01/10/2006-Ha Tinh City-VN                           }
    {     *School:Ha Tinh High School for the Gifted                  }
    {      (\_/)      <---------------------------------->            }
    {      (•_•)      {|Written by LeSonnn-SharkLord-Tk2|}            }
    {      />💻       <---------------------------------->            }
    {                                                                 }
    {                ________________________________                 }
    {               /    (Code)     /    (Debug)    /                 }
    {              /===============================/                  }
    {             <------------(Choose)------------>                  }
    { Goal:...                                                        }
    <=================================================================>
    It's never too late to start over
    If you're not happy with yesterday,try something different today
    Don't stay stuck
    Do better
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<unordered_map>
#include<queue>
#define task"ORZZ"
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long llu;
typedef pair<long long,long long>ii;
typedef tree<int,null_type,less<int>,
        rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//fastio
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file_inp(_s_) freopen((_s_).c_str(), "r", stdin)
#define file_out(_s_) freopen((_s_).c_str(), "w", stdout)
#pragma GCC optimize ("Ofast")
//struct-----pair
#define mp make_pair
#define vta first
#define vtb second
//vector
#define pb push_back
#define pf push_front
#define eb emplace_back
#define sz(a) (int)(a.size())
//loops
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOD(i,a,b) for(int i=a;i>=b;i--)
#define FORA(i,a,b) for(int i=a;i<b;i++)
#define FORB(i,a,b) for(int i=a-1;i>=b;i--)
#define REP(a,x) for(auto& a:x)
//endl-----'\n'
#define EL cout<<'\n'
#define ELE cout<<endl
//fast cin
inline int ReadInt()
{
    char ktn;
    for(ktn=getchar();ktn<'0'||ktn>'9';ktn=getchar());
    int mla=ktn-'0';
    for(ktn=getchar();ktn>='0'&&ktn<='9';ktn=getchar())
    mla=mla*10+ktn-'0';
    return mla;
}
void WriteInt(int mla)
{
    if(mla>9) WriteInt(mla/10);
    putchar(mla%10+'0');
}
//fast bp,bit,lcm
#define oo rand()%2000-1000
long long bpow(long long n,long long m,long long mod)
{
    long long res=1;while(m){if(m&1)res=res*n%mod;n=n*n%mod;m>>=1;}
    return res;
}
long long getbit(long long val,long long num)
{
    return ((val>>num)*1LL);
}
long long lcm(long long a,long long b)
{
    return a*b/__gcd(a,b);
}
//===============================================>>
void file(const string FILE="Test")
{
    freopen((FILE+".INP").c_str(),"r",stdin);
    freopen((FILE+".OUT").c_str(),"w",stdout);
}
//declare
const int maxN=5e2+68,mod=1e9+7;
ll a[maxN][maxN],b[maxN][maxN],pre[maxN],u[maxN],sum[maxN];
ll n,tga;
void cdt(ll n,ll a[maxN],ll b[maxN][maxN],ll ck[maxN])
{
    static ll x[maxN];
    FOR(i,1,n)
    {
        ll tg=0;
        FOR(j,1,n)
        {
            tg+=a[j]*b[j][i];
        }
        x[i]=tg;
    }
    FOR(i,1,n)
    {
        ck[i]=x[i];
    }
}
void solve()
{
    cin>>n;
    FOR(i,1,n)
    FOR(j,1,n)
    {
        cin>>a[i][j];
    }
    FOR(i,1,n)
    FOR(j,1,n)
    {
        cin>>b[i][j];
    }
    tga=1;
    for(int k=1;tga&&k<=5;k++)
    {
        FOR(i,1,n)
        {
            pre[i]=oo;
        }
        cdt(n,pre,a,u);
        cdt(n,u,a,u);
        cdt(n,u,a,u);
        cdt(n,pre,b,sum);
        FOR(i,1,n)
        {
            if(u[i]!=sum[i])
            {
                tga=0;
                break;
            }
        }
    }
    if(tga)
    {
        cout<<"YES"<<'\n';
        return;
    }
    else cout<<"NO"<<'\n';
}
//main
int main()
{
    //Written by LeSonnn
    fast
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ll nt;
    for(cin>>nt;nt--;)
    {
        solve();
    }
}
/**
Input:
2
2
0 1
1 1
1 2
2 2
2
0 1
1 1
1 2
2 3
Output:
NO
YES
**/
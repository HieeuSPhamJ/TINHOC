#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000006
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "Q"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 1e5 + 9;
int cnt[MAXN],a[MAXN],ans=1,n;
int power(int a,int b,int mod){
    int res = 1;
    while(b>0){
        if (b&1) res = (res * a) % mod;
        b>>=1;
        a = (a * a) % mod;
    }
    return res;
}
int cong(int a,int b,int mod){
    return (a + b) % mod;
}
int tru(int a,int b,int mod){
    return ((a - b) % mod + mod) % mod;
}
int nhan(int a,int b,int mod){
    return (a * b) %mod;
}
signed main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<MAXN;i++){
        for(int j=2 * i;j<MAXN;j+=i){
            cnt[i] = cong(cnt[i],cnt[j],MOD);
        }
        cnt[i] = tru(power(2,cnt[i],MOD) , 1,MOD);
        // cout << i << " " << cnt[i] << endl;
    }
    for(int i=10;i>=1;i--){
        for(int j=2 * i;j<MAXN;j+=i){
            cnt[i] = tru(cnt[i],cnt[j],MOD);
        }
        cout << i << " " << cnt[i] << endl;
        ans = nhan(ans,power(i,cnt[i],MOD+1),MOD+1);
    }
    cout<<ans<<endl;


}
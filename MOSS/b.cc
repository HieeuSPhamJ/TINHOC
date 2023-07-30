#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "1853B"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
int fib[109],n,t,k;
main()
{
    fast;
    freopen(TASKNAME".inp","r",stdin);
    freopen(TASKNAME".out","w",stdout);
    cin>>t;
    fib[1] = 1;
    fib[2] = 1;
    for(int i=3;i<=30;i++){
        fib[i] = fib[i-1] + fib[i-2];
//        cout<<fib[i]<<endl;
    }
    while(t--){
        cin>>n>>k;
        if (k>30) cout<<0<<endl;
        else if (n==0) cout<<1<<endl;
        else{
            int ans = 0;
            int b = fib[k-1];
            int a = fib[k-2];
            for(int j=1;j<=n/b;j++){
               int x = n - j * b;
               if (x%a == 0 && x/a <= j) {
                  ans++;
               }
            }
            cout<<ans<<endl;
        }


    }
}

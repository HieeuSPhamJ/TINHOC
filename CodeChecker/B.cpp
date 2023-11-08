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
#define TASKNAME "A"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 2e3 + 9;
int n,a[MAXN],T,ans=0,g=1,mn = INF;
bool dp[200005];
int pre[200005];
vector<int> onlyelement;
main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if (i==1) g = a[i];
        else g = __gcd(g,a[i]);
        bool check = false;
        for(int j=i-1;j>=1;j--){
            if (a[i] % a[j] == 0) {
                check = true;
            }
        }
        if (!check) onlyelement.pb(i), mn = min(mn, a[i]);
    }
    if (g > 1){
        cout<<T / g + 1<<endl;
    }
    else{
        dp[0] = true;
        if (T <= 200000){
            for(int i=0;i<=T;i++){
                for(auto x: onlyelement){
                    if (i >= a[x]) dp[i] |= dp[i-a[x]];
                    if (dp[i]) break;
                }
                ans += dp[i];
            }
            cout<<ans<<endl;
        }
        else{
            bool kt = false;
            pre[0] = 1;
            for(int i=0;i<=200000;i++){
                for(auto x: onlyelement){
                    if (i >= a[x]) dp[i] |= dp[i-a[x]];
                    if (dp[i]) break;
                }
                ans += dp[i];
                pre[i] = ans;
                if (i>=mn and pre[i] - pre[i-mn] == mn) kt = true;
            }
            if (kt) cout<<ans + T - 200000<<endl;
        }

    }


}


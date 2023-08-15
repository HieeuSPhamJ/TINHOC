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
#define TASKNAME "fibodistribute"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 5e5 + 9;
int fibo[90],n,a[MAXN],pre[MAXN],dp[MAXN];
void add(int &a,int b){
    a += b;
    if (a>=MOD) a-=MOD;
}
unordered_map<int,int> mp;
main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    fibo[1] = 1;
    fibo[2] = 2;
    int num = 0;
    for(int i=3;i<=89;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if (fibo[i] >= 1e14){
            num = i;
            break;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        mp[pre[i]] = i;
    }

    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=num;j++){
            if (pre[i] - fibo[j] < 0) break;
            int pos = mp[pre[i] - fibo[j]];
            if (pre[i] - fibo[j] != 0 and pos == 0) continue;
            else add(dp[i],dp[pos]);
        }
    }
    cout<<dp[n]<<endl;
}
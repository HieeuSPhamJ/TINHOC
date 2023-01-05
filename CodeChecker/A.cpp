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
#define TASKNAME "KM2"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

const int MAXN = 2e5 + 9;

int n,a[MAXN],pre[MAXN],prefixsum[MAXN],m,k,dp[MAXN];
signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        prefixsum[i] = prefixsum[i-1] + a[i];
        dp[i] = INF;
    }
    int x = INF;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        pre[l] = max(pre[l],r);
        x = min(x,l);
    }

    for(int i=1;i<x;i++){
        dp[i] = dp[i-1] + a[i];
    }
    for(int i=x;i<=k;i++){
        dp[i] = dp[i-1] + a[i];
        for(int j=k;j>=0;j--){
           if (pre[j]>0 && i>=j){
               dp[i] = min(dp[i], dp[i-j] + (prefixsum[i] - prefixsum[i-j + pre[j]]));
           }
        }
    }
    cout<<dp[k];
}

#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e9 + 7;

int n, m, k;
int gap;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN];
int vis[maxN];

int dfs(int nu, int ty){
    if (vis[nu]){
        return dp[nu];
    }
    if (a[nu] > gap){
        return 0;
    }
    dp[nu] = 1;
    vis[nu] = ty;
    for (auto i: adj[nu]){
        if (a[i] > gap){
            continue;
        }
        if (vis[i] == ty){
            dp[nu] = inf;
            return dp[nu];
        }
        dp[nu] = max(dp[nu], dfs(i, ty) + 1);
    }
    return dp[nu];
}


bool check(){
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        vis[i] = 0;
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= gap){
            res = max(res, dfs(i,i));
        }
    }

    return res >= k;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int res = 0;
    int l = 0;
    int r = 1e18;
    while(l <= r){
        int mid = (l + r) / 2;
        gap = mid;
        if (check()){
            r = mid - 1;
            res = mid;
        }
        else{
            l = mid + 1;
        }
    }
    // gap = 2;
    // cout << check() << endl;
    cout << res << endl;
    return 0;
}
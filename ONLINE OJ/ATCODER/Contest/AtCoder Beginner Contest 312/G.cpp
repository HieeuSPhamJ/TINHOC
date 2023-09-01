#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int n;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN];
int dp2[maxN];
int tdp[maxN];
int child[maxN];
int lvl[maxN];


void dfs(int nu, int fa){
    child[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        lvl[i] = lvl[nu] + 1;
        dfs(i, nu);
        child[nu] += child[i];
        dp[nu] += dp[i];
    }
    dp[nu] += (child[nu] - 1);
}

void dfs2(int nu, int fa){
    if (nu != fa){
        tdp[nu] = dp[nu] + tdp[fa] - dp[nu] - child[nu] + (n - child[nu]);
        dp2[nu] = tdp[nu] - dp[nu];
        // cout << nu << ": " << dp2[nu] << "|" << dp[nu] << " " << tdp[fa] << " " << dp[nu] << " " << child[nu] << endl;
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs2(i,nu);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    tdp[1] = dp[1];
    dfs2(1,1);
    for (int i = 1; i <= n; i++){
        // cout << i << ": " << tdp[i] << " " << dp[i] << " " << dp2[i] << endl;
        dp[i] -= (child[i] - 1);
        dp2[i] -= (n - child[i]);
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        res += dp[i] + dp2[i];    
    }

    res /= 2;

    res = n * (n - 1) * (n - 2) / 6 - res;

    cout << res << endl;

    return 0;
}
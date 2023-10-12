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

vector <int> adj[maxN];
int dp1[maxN];
int dp2[maxN];
int dp[maxN];
int mk[maxN];

void dfs1(int nu, int fa){
    dp1[nu] = -1e18;
    if (mk[nu]){
        dp1[nu] = 0;
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs1(i,nu);
        dp1[nu] = max(dp1[nu], dp1[i] + 1);
    }
}

void dfs2(int nu, int fa){
    dp[nu] = dp1[nu];
    dp[nu] = max(dp[nu], dp2[fa] + 1);
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs2(i,nu);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        mk[0] = 0;
    }
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        mk[x] = 1;
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,1);
    dp2[1] = -1e18;
    dp[1] = dp1[1];
    dfs2(1,1);
    for (int i = 1; i <= n; i++){
        cout << total[i] << endl;
    }

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
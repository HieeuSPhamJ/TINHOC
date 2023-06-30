#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

vector <int> adj[maxN];
int a[maxN];
int dp[maxN];
int ma = -1e18;

void dfs0(int nu, int fa){
    dp[nu] = a[nu];
    int res = 0;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs0(i, nu);
        res += max(0ll, dp[i]);
    }
    dp[nu] += res;
    ma = max(ma, dp[nu]);
}


int cnt = 0;

void dfs1(int nu, int fa){
    dp[nu] = a[nu];
    int res = 0;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs1(i, nu);
        res += max(0ll, dp[i]);
    }
    dp[nu] += res;
    if (dp[nu] == ma){
        cnt++;
        dp[nu] = 0;
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs0(1,1);
    dfs1(1,1);



    cout << cnt * ma << " " << cnt << endl;
    return 0;
}
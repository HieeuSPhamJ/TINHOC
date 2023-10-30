#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN][101][2];
int res = 0;

void dfs(int nu, int fa){
    dp[nu][0][0] = 0;
    int co = 0;
    for (auto x: adj[nu]){
        if (x == fa){
            continue;
        }
        co += a[x];
    }
    // cout << "With: " << nu << endl;
    for (int i = 1; i <= k; i++){
        dp[nu][i][0] = max({dp[fa][i][0] + a[i] - a[i], dp[fa][i][1]});
        dp[nu][i][1] = max({dp[fa][i - 1][0] + co + a[i] - a[i], dp[fa][i - 1][1] + co - a[fa], dp[fa][i - 1][1] + co});
        // cout << i << " " << dp[nu][i][0] << " " << dp[nu][i][1] << endl;
        res = max({res, dp[nu][i][0], dp[nu][i][1]});
    }

    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("TOMJERRY.inp", "r")) {
        freopen("TOMJERRY.inp", "r", stdin);
        freopen("TOMJERRY.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (n <= 1000){
        res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                dp[i][j][0] = dp[i][j][1] = 0;
            }
            // cout << "=======" << endl;
            dfs(i,0);
        }
        cout << res << endl;
    }
    else{
        dfs(1,0);
        cout << res << endl;
    }
    
    return 0;
}
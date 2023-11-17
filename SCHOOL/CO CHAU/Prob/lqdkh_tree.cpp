#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
int dp[maxN];
vector <int> adj[maxN];
int res = 0;

void dfs(int nu, int fa){
    dp[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        } 
        dfs(i,nu);
        dp[nu] += dp[i];
    }
    // cout << nu << " " << dp[nu] << endl;
    if (dp[nu] >= k){
        // cout << "cut " << nu << endl;
        dp[nu] = 0;
        res++;
    }
}
signed main(){
    freopen("tree.INP", "r", stdin);
    freopen("tree.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1,1);
    cout << res << endl;
    return 0;
}
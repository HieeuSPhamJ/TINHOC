#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 400 + 10;

int n, k;
int ans = 1e18;
vector <int> adj[maxN];
int dp[maxN][maxN];

void dfs(int node, int father){
    dp[node][0] = 0;
    dp[node][1] = 0;
    for (auto nu: adj[node]){
        if (nu == father){
            continue;
        }
        dfs(nu, node);    
        cout << "Node: " << node << " " << nu << endl;
        for (int i = 1; i <= k; i++){
            dp[node][k] = min(dp[node][k], dp[nu][k - 1]);
            cout << dp[node][k] << " ";
        }
        cout << endl;
    }
    ans = min(ans, dp[node][k]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = 1e18;
        }
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    cout << ans;
    return 0;
}
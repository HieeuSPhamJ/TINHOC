#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

vector <int> adj[maxN];
int dp[maxN];
int si[maxN];
int ans = 0;
int dp2[maxN];
int n;

void dfs1(int node, int father){
    si[node] = 1;
    for (auto i: adj[node]){
        if (i == father){
            continue;
        }
        dfs1(i,node);
        si[node] += si[i];
        dp[node] += dp[i];
    }
    dp[node] += si[node];
}

void dfs(int node, int father){
    // cout << "Node: " << node << " " << father << endl;
    if (node == father){
        // cout << "Root: " << dp2[node] << endl;
        ans = max(ans, dp[node]);
    }
    else{
        int now = dp2[father] - dp[node] - si[node];
        // cout << now << " ";  
        for (auto newNode: adj[node]){
            if (newNode == father){
                continue;
            }
            now += dp[newNode];
        }
        now += n;
        dp2[node] = now;
        ans = max(ans, dp2[node]);
        // cout << dp2[node] << endl;
    }
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dfs(newNode, node);
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
    dfs1(1,1);

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << dp[i] << endl;
    // }

    dp2[1] = dp[1];

    dfs(1,1);

    cout << ans;

    return 0;
}

/*

*/
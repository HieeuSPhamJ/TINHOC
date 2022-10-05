#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int dp[maxN];
int n, m;
int ans[maxN];
vector <ii> adj[maxN];
int res;

void DFS(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        DFS(newNode.se, node);
        dp[node] += dp[newNode.se];
        ans[newNode.se] = (n - dp[newNode.se]) * dp[newNode.se]; 
        res += ans[newNode.se] * newNode.fi;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    DFS(1,1);
    cout << res;

    return 0;
}
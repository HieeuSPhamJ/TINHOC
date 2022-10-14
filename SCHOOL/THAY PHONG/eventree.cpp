#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int dp[maxN];
int n, m;
int ans[maxN];
vector <int> adj[maxN];
int res;

void DFS(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        dp[node] += dp[newNode];
    }
    if (dp[node] % 2 == 0){
        res++;
        dp[node] = 0;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,1);
    cout << res - 1;
    return 0;
}
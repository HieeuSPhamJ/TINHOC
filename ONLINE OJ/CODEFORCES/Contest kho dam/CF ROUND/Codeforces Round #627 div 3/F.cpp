#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int dp[maxN];
int dp2[maxN];
int ans[maxN];
vector <int> adj[maxN];
int dad[maxN];

void dfs1(int node, int father){
    dp[node] = a[node];
    for (int newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dad[newNode] = node;
        dfs1(newNode, node);
        dp[node] = max(dp[node], dp[node] + dp[newNode]);
    }
}

void dfs(int node, int father){
    if (node != father){    
        // cout << "Node: " << node << " " << father << endl;
        ans[node] = dp[node];
        dp2[father] = a[father];
        for (int newNode: adj[father]){
            if (newNode == node){
                continue;
            }
            if (newNode == dad[father]){
                dp2[father] = max(dp2[father], dp2[father] + dp2[newNode]);
                // cout << newNode  << "-dad ";
                continue;
            }
            // cout << newNode << "-child "; 
            dp2[father] = max(dp2[father], dp2[father] + dp[newNode]);
        }
        // cout << endl;
        // cout << ans[node] << " " << dp2[father] << " ";
        ans[node] = max(ans[node], ans[node] + dp2[father]);
        // cout << ans[node] << endl;
    }
    for (int newNode: adj[node]){
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 0){
            a[i] = -1;
        }
    }

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

    ans[1] = dp[1];

    dfs(1,1);


    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
1: 0
2: 1
3: 1
4: 2
5: 0
6: -1
7: -1
8: -1
9: 1
*/
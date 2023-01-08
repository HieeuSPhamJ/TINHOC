#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;


const int maxN = 2 * 1e5 + 10;

int father[maxN];

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

vector <int> adj1[maxN], adj2[maxN];
int height[maxN];
int dp[maxN];
int dp2[maxN];
int check[maxN];
int prefather[maxN];


void getheight(int node, int root){
    for (auto newNode: adj1[node]){
        if (newNode == root){
            continue;
        }
        height[newNode] = height[node] + 1;
        getheight(newNode, node);
    }
}

void dfs(int node, int root){
    // cout << "Node: " << node << endl;
    check[node] = 1;
    dp[node] = 0;
    for (auto newNode: adj2[node]){
        if (newNode == root){
            continue;
        }
        prefather[newNode] = node;
        dfs(newNode, node);
        dp[node] = max(dp[node], dp[newNode] + 1);
    }
}

void allroot(int node, int root){
    if (node != root){
        // cout << "Node: " << node << " " << root << " " << prefather[root] << endl;
        for (auto newNode: adj2[root]){
            if (newNode == node){
                continue;
            }
            if (newNode == prefather[root]){
                // cout << "dad: " << newNode << "-" << dp2[newNode] << endl;
                dp2[node] = max(dp2[node], dp2[newNode] + 2);
                continue;
            }
            
            // cout << "child: " << newNode << "-" << dp[newNode] << endl;
            dp2[node] = max(dp2[node], dp[newNode] + 2);
        }
    }
    for (auto newNode: adj2[node]){
        if (newNode == root){
            continue;
        }
        allroot(newNode, node);
    }
}

signed main(){
    freopen("S162077.INP", "r", stdin);
    freopen("S162077.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    vector <ii> E;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        E.push_back({a,b});
    }
    

    for (auto tempE: E){
        int a = findFather(tempE.fi);
        int b = findFather(tempE.se);
        if (a == b){
            adj2[tempE.fi].push_back(tempE.se);
            adj2[tempE.se].push_back(tempE.fi);
            continue;
        }
        // cout << tempE.fi << " " << tempE.se << endl;
        adj1[tempE.fi].push_back(tempE.se);
        adj1[tempE.se].push_back(tempE.fi);
        father[a] = b;
    }

    getheight(1,1);
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            // cout << i << endl;
            dfs(i,i);
            allroot(i,i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        // cout << i << ": " << dp[i] << " " << dp2[i] << endl;
        ans = max(ans, height[i] + max(dp[i],dp2[i]));    
    }

    cout << ans;

    return 0;
}
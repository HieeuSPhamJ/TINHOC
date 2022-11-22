#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
vector <ii> adj[maxN];
int father[maxN][20];
int level[maxN];
int height[maxN];

void DFS(int node, int daddy){
    for (auto newNode: adj[node]){
        if (newNode.se == daddy){
            continue;
        }
        father[newNode.se][0] = node;
        height[newNode.se] = height[node] + newNode.fi;
        level[newNode.se] = level[node] + 1;
        DFS(newNode.se, node);
    }
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if (level[a] < level[b]){
        swap(a,b);
    }
    for (int i = log2(level[a]); i >= 0; i--){
        if (level[father[a][i]] >= level[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(level[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    DFS(1,1);
    init();

    while(test--){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        cout << height[a] + height[b] - height[lca] * 2 << endl;
    }

    return 0;
}

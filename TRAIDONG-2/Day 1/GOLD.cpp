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
const int mod = 1e9 + 7;

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
    if (fopen("GOLD.inp", "r")) {
        freopen("GOLD.inp", "r", stdin);
        freopen("GOLD.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int g;
    cin >> n >> g;
    for (int i = 1; i < n; i++){
        int a, b, w, c;
        cin >> a >> b >> w >> c;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    DFS(1,1);
    init();
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> a >> b;
        int lca = LCA(a, b);
        // cout << lca << " ";
        cout << (((height[a] + height[b] - height[lca] * 2) % mod) * g) % mod << endl;
    }

    return 0;
}

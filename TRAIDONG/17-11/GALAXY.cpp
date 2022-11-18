#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
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
        height[newNode.se] = (height[node] xor newNode.fi);
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
            // cout << level[a] << " " << level[b] << endl;
        }
    }
    // cout << "In" << a << " " << b << endl;
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

int len(int a, int b){
    int lca = LCA(a, b);
    // cout << a << " " << b << endl;
    // cout << lca << ": ";
    return ((height[a] xor height[b]) xor height[lca] xor height[lca]);

}

int ans = 0;
int check[maxN];
int tans[maxN];
int root[maxN];
int com[maxN];

int checkRoot(int v){
    if (root[v]==v){
        return v;
    }
    else return (root[v]=checkRoot(root[v]));
}

int C(int x){
    return x * (x - 1) / 2;
}


void Union(int a, int b){
    int u = checkRoot(a);
    int v = checkRoot(b);
    // cout << a << " " << b << endl;
    ans -= tans[u];
    ans -= tans[v];
    root[v] = u;
    com[u] += com[v];
    // for (int i = 1; i <= n; i++){
    //     cout << com[i] << " ";
    // }
    // cout << endl;
    tans[u] = C(com[u]);
    ans += tans[u];

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector <ii> E;
    for (int i = 1; i <= n; i++){
        root[i] = i;
        com[i] = 1;
    }
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        E.push_back({a,b});
    }

    DFS(1,1);
    init();
    test = n;
    vector <int> lists;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        lists.push_back(x);
    }
    reverse(all(lists));
    vector <int> res;
    res.push_back(0);
    while(!lists.empty()){
        Union(E[lists.back() - 1].fi, E[lists.back() - 1].se);
        res.push_back(ans);
        lists.pop_back();
    }

    while(!res.empty()){
        cout << res.back() << endl;
        res.pop_back();
    }

    return 0;
}

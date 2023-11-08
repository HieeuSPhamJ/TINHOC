#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;


int n, m, k;
vector <int> adj[maxN];
int rt[maxN];
int res[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int mk[maxN];
int father[maxN][20];
int level[maxN];
int ck[maxN];
int lg[maxN];

void DFS(int node, int daddy){
    for (auto newNode: adj[node]){
        if (newNode == daddy){
            continue;
        }
        father[newNode][0] = node;
        level[newNode] = level[node] + 1;
        DFS(newNode, node);
    }
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= lg[n]; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if (level[a] < level[b]){
        swap(a,b);
    }
    if (level[a] != level[b]){
        for (int i = lg[level[a]]; i >= 0; i--){
            if (level[father[a][i]] >= level[b]){
                a = father[a][i];
            }
        }
    }

    if (a == b){
        return a;
    }

    for (int i = lg[level[a]]; father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        mk[nu] += mk[i];
    }
    if (mk[nu]){
        ck[nu] = 1;
        ck[fa] = 1;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    lg[0] = 0;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
        lg[i] = log2(i);
    }
    vector <pair<int,ii>> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        if (u == v){
            continue;
        }
        ls.push_back({i,{a,b}});
        // cout << a << " " << b << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
        rt[u] = v;
    }

    DFS(1,1);
    init();

    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a,b);
        mk[a]++;
        mk[lca]--;
        mk[b]++;
        mk[lca]--;
        
    }

    dfs(1,1);

    for (auto i: ls){
        if (ck[i.se.fi] and ck[i.se.se]){
            res[i.fi] = 1;
        }
    }

    for (int i = 1; i <= m; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
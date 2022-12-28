#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int low[maxN];
int num[maxN];
int cnt = 1;
map <ii,int> check;
int n, test;
vector <ii> nadj[maxN];
int father[maxN][20];
int level[maxN];
int height[maxN];

void DFS(int node){
    // cout << node << endl;
    num[node] = 1;
    for (auto newNode: nadj[node]){
        if (num[newNode.se]){
            continue;
        }
        father[newNode.se][0] = node;
        height[newNode.se] = height[node] + newNode.fi;
        level[newNode.se] = level[node] + 1;
        DFS(newNode.se);
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

void timcau(int node, int father){
    // cout << node << endl;
    low[node] = num[node] = cnt;
    cnt++;
    for (auto nu: adj[node]){
        if (nu == father){
            continue;
        }
        if (num[nu]){
            low[node] = min(low[node], num[nu]);
        }
        else{
            timcau(nu, node);
            low[node] = min(low[node], low[nu]);
            if (low[nu] >= num[nu]){
                // cout << node << " " << nu << endl;
                check[{nu,node}] = 1;
                check[{node,nu}] = 1;
                
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            timcau(i,i);
        }
    }


    for (int i = 1; i <= n; i++){
        for (auto e: adj[i]){
            nadj[i].push_back({check[{i,e}],e});
        }
    }
    
    memset(num,0,sizeof(num));
    DFS(1);
    init();

    cin >> test;

    while(test--){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        cout << height[a] + height[b] - height[lca] * 2 << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
vector <int> adj[maxN];
int father[maxN][20];
int level[maxN];
int height[maxN];
int prefix[maxN];
int ans[maxN];

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
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

void adu(int node, int father){
    ans[node] = prefix[node];

    for (auto nu: adj[node]){
        if (nu == father){
            continue;
        }
        adu(nu,node);
        ans[node] += ans[nu];
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
    cin >> n;
    vector <ii> lists;
    for (int i = 1, cnt = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        lists.push_back({a,b});
    }

    DFS(1,1);
    init();

    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a,b);

        prefix[a]++;
        prefix[b]++;
        prefix[lca] -= 2;

    }

    adu(1,1);


    // for (int i = 1; i <= n; i++){
    //     cout << ans[i] << " ";
    // }

    for (auto i: lists){
        int t = i.fi;
        if (level[i.fi] < level[i.se]){
            t = i.se;
        }
        cout << ans[t] << " ";
    }

    return 0;
}

#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

vector <int> adj[maxN];
int down[maxN];
int up[maxN];
int dad[maxN];

void bfs1(int node, int father){
    down[node] = 1;
    dad[node] = father;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        bfs1(newNode, node);
        down[node] = max(down[node], down[newNode] + 1);
    }
}

void bfs2(int node, int father){
    up[node] = max(up[node], up[father] + 1);
    for (auto anoChild: adj[father]){
        if (anoChild == father or anoChild == node or dad[father] == anoChild){
            continue;
        }
        // cout << anoChild << " ";
        up[node] = max(up[node], down[anoChild] + 1);
    }  
    // cout << endl;
    // cout << "Node: " << node << " " << up[node] << endl;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        bfs2(newNode, node);
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
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs1(1,1);
    bfs2(1,0);
    int dem = 0;
    for (int i = 1; i <= n; i++){
        dem = max(dem, up[i] + down[i] - 2);
        // cout << i << ": " << up[i] << " " << down[i] << endl;
    }

    for (int i = 1; i <= n; i++){
        int ndem = 0;
        ndem = max(up[i], down[i]);
        cout << max(ndem, dem) << endl;
    }
    return 0;
}
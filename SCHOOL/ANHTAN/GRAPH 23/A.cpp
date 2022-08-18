#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
vector <ii> adj[maxN];
int father[maxN][65];
int height[maxN];
int len[maxN];

void init(){
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

void DFS(int node, int khang){
    for (auto newNode: adj[node]){
        if (newNode.se == khang){
            continue;
        }
        father[newNode.se][0] = node;
        height[newNode.se] = height[node] + 1;
        len[newNode.se] = len[node] + newNode.fi;
        DFS(newNode.se, node);
    }
}

int LCA(int a, int b){
    if (height[a] < height[b]){
        swap(a, b);
    }
 
    for (int i = log2(height[a]); height[a] != height[b]; i--){
        if (height[a] - height[b] >= (1 << i)){
            a = father[a][i];
        }
    }
 
    int quickRun = n;
 
    // cout << a << ' ' << b << endl;
 
    if (a == b){
        return a;
    }
 
    // while(father[a][0] != father[b][0]){
    //     while(father[a][quickRun] == father[b][quickRun]){
    //         quickRun--;
    //     }
    //     a = father[a][quickRun];
    //     b = father[b][quickRun];
    // }
 
    for (int i = log2(height[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
 
    return father[a][0];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    DFS(1,1);
    init();

    while(test--){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        // cout << lca << ' ';
        cout << len[a] + len[b] - len[lca] * 2;
        cout << endl;
    }

    return 0;
}
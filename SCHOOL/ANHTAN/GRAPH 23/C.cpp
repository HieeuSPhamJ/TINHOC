#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
map <int,map <int,int>> checkMap;
vector <int> adj[maxN];
int father[maxN][33];
int height[maxN];
int path[maxN];

void init(){
    path[1] = 1;
    height[0] = -1;
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

void DFS(int node, int khang){
    for (auto newNode: adj[node]){
        if (newNode == khang){
            continue;
        }
        father[newNode][0] = node;
        path[newNode] = node;
        height[newNode] = height[node] + 1;
        DFS(newNode, node);
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
int go(int a, int b){
    // cout << a << " " << b << endl;
    if (height[a] < height[b]){
        return b;
    }
    if (a == b){
        return b;
    } 
    if (checkMap[father[a][0]][a] == 0 and checkMap[a][father[a][0]] == 0){
        checkMap[a][father[a][0]] = 1;
        checkMap[father[a][0]][a] = 1;
        // cout << a << " " << father[a][0] << endl;
        return path[a] = go(path[a], b);
    }
    else{
        return go(path[a], b);
    }

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    vector <ii> listE;

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        listE.push_back({a,b});
    }
    
    DFS(1, 1);
    init();

    int test;
    cin >> test;

    while(test--){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a,b);
        // cout << a << " " << b << " " << lca << endl;
        go(a, lca);
        go(b, lca);
        // for (int i = 1; i <= n; i++){
        //     cout << i << ":" << path[i] << " ";
        // }
        // cout << endl;
    }

    int count = 0;

    for (auto i: listE){
        if (checkMap[i.fi][i.se] == 0){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e6 + 10;

int n, k;
vector <ii> adj[maxN];
int father[maxN][65];
int height[maxN];
int len[maxN];
int checkNode[maxN];
int visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void init(){
    father[1][0] = 0;
    height[0] = -1;
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


void Dickcha(){
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    for (int i = 1; i <= n; i++){
        visited[i] = inf;
    }

    DFS(1,1);
    init();
    vector <int> V;
    for (int i = 1; i <= k; i++){
        int inp;
        cin >> inp;
        V.push_back(inp);
    }
    int root = V[0];
    for (int i = 1; i < V.size(); i++){
        root = LCA(root, V[i]);
    }
    // cout << root << endl;
    checkNode[root] = 1;
    for (auto i: V){
        int node = i;
        while(node != root and !checkNode[node]){
            checkNode[node] = 1;
            node = father[node][0];
        }
    }

    for (int i = 1; i <= n; i++){
        if (checkNode[i]){
            visited[i] = 0;
            myHeap.push({0,i});
        }
    }

    Dickcha();

    for (int i = 1; i <= n; i++){
        if (visited[i] == inf){
            cout << -1 << endl;
        }
        else{
            cout << visited[i] << endl;
        }
    }
    return 0;
}
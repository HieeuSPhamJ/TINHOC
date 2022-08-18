#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int root = 0;
vector <int> adj[maxN];
vector <int> party[maxN];
int father[maxN][64];
// int height[maxN];
int n, m;

void init(){
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];       
        }
    }
}

void getPrefix(int node, int khang){
    for (auto newNode: adj[node]){
        if (newNode == khang){
            continue;
        }
        father[newNode][0] = node;
        height[newNode] = height[node] + 1;
        getPrefix(newNode, node);
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

int calLen(int a, int b){
    // cout << a << " " << b << " " << LCA(a, b) << endl;
    return height[a] + height[b] - 2 * height[LCA(a,b)];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        party[x].push_back(i);
        if (y == 0){
            root = i;
        }
        else{
            adj[i].push_back(y);
            adj[y].push_back(i);
            // cout << i << " " << y << endl;
        }
    }

    getPrefix(root, root);
    init();
    
    // for (int i = 1; i <= n; i++){
    //     cout << father[i][0] << " " << height[i] << endl;
    // }

    for (int i = 1; i <= m; i++){
        int root = party[i][0];
        int maxLen = 0;
        int anoRoot = root;
        for (auto j: party[i]){
            int len = calLen(root, j);
            if (len >= maxLen){
                maxLen = len;
                anoRoot = j;
            }
        }

        int anoMaxLen = 0;

        for (auto j: party[i]){
            int len = calLen(anoRoot, j);
            if (len >= anoMaxLen){
                anoMaxLen = len;
            }
        }
        // cout << anoMaxLen << " " << maxLen << "-";
        cout << anoMaxLen << endl;
    }
    return 0;
}
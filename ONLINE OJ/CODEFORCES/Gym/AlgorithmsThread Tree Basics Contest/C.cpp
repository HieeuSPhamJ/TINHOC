#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxN = 3 * 1e5 + 10;

int n;
vector <int> adj[maxN];
int level[maxN];
int father[maxN][30];


void dfs(int node, int dad){
    for (auto newNode: adj[node]){
        if (newNode == dad){
            continue;
        }
        level[newNode] = level[node] + 1;
        father[newNode][0] = node;
        dfs(newNode, node);
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
    if (a == b){
        return a;
    }

    if (level[a] < level[b]){
        swap(a,b);
    }
    // cout << a << " " << b << endl;
    for (int i = log2(level[a]); i >= 0; i--){
        if (level[father[a][i]] >= level[b]){
            a = father[a][i];
        }
    }
    
    // cout << a << " " << b << endl;
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
    int lca = LCA(a,b);
    return level[a] + level[b] - 2 * level[lca];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int test;
    cin >> test;
    dfs(1,1);
    init();
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << father[i][0] << " " << level[i] << endl;
    // }
    while(test--){
        int a, b, w;
        cin >> a >> b >> w;
        if (len(a,b) <= w){
            cout << b << endl;
            continue;
        }
        int lca = LCA(a,b);
        // cout << a << " " << b << " lca:" << lca <<endl; 
        if (a == lca){
            int goal = level[a] + w;
            a = b;
            for (int i = log2(level[a]); i >= 0; i--){
                if (level[father[a][i]] >= goal){
                    a = father[a][i];
                }
            }
            cout << a << endl;
        }
        else if (b == lca){
            int goal = level[a] - w;
            for (int i = log2(level[a]); i >= 0; i--){
                if (level[father[a][i]] >= goal){
                    a = father[a][i];
                }
            }
            cout << a << endl;
        }
        else if (len(a, lca) >= w){
            // cout << "First " << len(a, lca) << endl;
            int goal = level[a] - w;
            for (int i = log2(level[a]); i >= 0; i--){
                if (level[father[a][i]] >= goal){
                    a = father[a][i];
                }
            }
            cout << a << endl;
        }
        else{
            // cout << "Second" << endl;
            int goal = level[lca] + (w - len(a, lca));
            // cout << level[6] << endl;
            int a = b;
            for (int i = log2(level[a]); i >= 0; i--){
                if (level[father[a][i]] >= goal){
                    a = father[a][i];
                }
            }
            cout << a << endl;
        }
        // cout << lca << endl;
    }
    return 0;
}
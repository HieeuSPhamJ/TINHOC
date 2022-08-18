#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


const int maxN = 2 * 1e5 + 10;

int n, test;
vector <int> adj[maxN];
int father[maxN][33];
int height[maxN];
int check[maxN];

void init(){
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
 
    if (a == b){
        return a;
    }
 
    for (int i = log2(height[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
 
    return father[a][0];
}

bool cmp(int a, int b){
    return height[a] < height[b];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    DFS(1, 1);
    init();

    while(test--){
        int m;
        cin >> m;
        vector <int> listE;
        int lca;
        
        for (int i = 1; i <= m; i++){
            int inp;
            cin >> inp;
            listE.push_back(father[inp][0]);
            lca = father[inp][0];
        }

        sort(listE.begin(), listE.end(), cmp);

        if (listE.size() == 1){
            cout << "YES" << endl;
            continue;
        }

        int check = 0;

        // for (auto i: listE){
        //     cout << i << " ";
        // }
        // cout << endl;

        for (int i = listE.size() - 2; i >= 0; i--){
            lca = LCA(listE[i], listE[i + 1]);
            // cout << listE[i] << " " << listE[i + 1] << "|" << lca << endl;
            if (lca == listE[i]){
                listE.pop_back();
            }
            else{
                check = 1;
                break;
            }
        }

        // cout << lca << endl;

        if (check == 0){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;

    }
    return 0;
}
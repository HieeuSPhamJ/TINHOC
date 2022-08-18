#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 200010;

int a[maxN];
int ans[maxN];
int check[maxN];
set <int> tempAns[maxN];
vector <int> adj[maxN];

void DFS(int node, int father){
    tempAns[node].insert(a[node]);
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        if (tempAns[node].size() < tempAns[newNode].size()){
            swap(tempAns[node], tempAns[newNode]);
        }
        for (auto i: tempAns[newNode]){
            tempAns[node].insert(i);
        }
        tempAns[newNode].clear();
    }
    ans[node] = tempAns[node].size();
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            tempAns[i].clear();
            adj[i].clear();
            check[i] = 0;
            ans[i] = 0;
        }

        for (int i = 1; i <= n; i++){
            int m;
            cin >> m;
            for (int j = 1; j <= m; j++){
                int inp;
                cin >> inp;
                adj[i].push_back(inp);
                adj[inp].push_back(i);
                // cout << i << ' ' << inp << endl;
                check[inp] = 1;
            }
        }

        int root = -1;
        for (int i = 1; i <= n; i++){
            if (check[i] == 0){
                root = i;
                break;
            }
        }

        DFS(root, root);

        for (int i = 1; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int n;
int res = 0;
int root;
int a[4][maxN];
vector <int> adj[maxN];
vector <int> listNode;
vector <int> listColor[6] = {
                                {1,2,3},
                                {1,3,2},
                                {2,1,3},
                                {2,3,1},
                                {3,1,2},
                                {3,2,1}
                            };
int ans[maxN];
int dp[4][maxN];

void DFS(int node, int father){
    // cout << node << endl;
    listNode.push_back(node);
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }    
        DFS(newNode, node);

    }
}

bool checkLine(){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (adj[i].size() == 2){
            count++;
        }
    }
    if (count != n - 2){
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (adj[i].size() == 1){
            count++;
            root = i;
        }
    }
    if (count == n){
        return 1;
    }
    return 0;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (checkLine() == 0){
        cout << -1;
        return 0;
    }

    DFS(root, root);
    res = 1e18;

    for (int color = 0; color < 6; color++){
        int tempRes = 0;
        for (int i = 0; i < n; i++){
            int node = listNode[i];
            tempRes += a[listColor[color][i % 3]][node];
            // cout << node << ": " << listColor[color][i % 3] << endl;
        }
        // cout << endl;

        if (res > tempRes){
            res = tempRes;
            for (int i = 0; i < n; i++){
                int node = listNode[i];
                ans[node] = listColor[color][i % 3];
            }
        }
        // cout << tempRes << endl;
    }

    cout << res << endl;
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
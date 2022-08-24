#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int n, m, a, b;
vector <int> adj[4][maxN];
int visited[4][maxN];
int countNode[4];
int diff[3];

void dfs(int type, int node){
    // cout << node << " ";
    visited[type][node] = 1;
    for (auto newNode: adj[type][node]){
        if (visited[type][newNode] == 1){
            continue;
        }
        dfs(type,newNode);
    }
}

void init(){
    for (int i = 0; i <= n; i++){
        adj[0][i].clear();
        adj[1][i].clear();

    }
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
        cin >> n >> m >> a >> b;
        init();
        for (int i = 1; i <= m; i++){
            int x, y;
            cin >> x >> y;
            if (x != b and y!= b){
                adj[0][x].push_back(y);
                adj[0][y].push_back(x);
                // cout << "A" << ": " << x << " " << y << endl;
            }
            if (x != a and y!= a){
                adj[1][x].push_back(y);
                adj[1][y].push_back(x);
                // cout << x << " " << y << endl;
            }
        }

        diff[0] = a;
        diff[1] = b;
        dfs(0,a);
        dfs(1,b);

        for (int i = 1; i <= n; i++){
            // cout << visited[0][i] << " " << visited[1][i] << endl;
            if (i != diff[0] and visited[0][i] == 1 and visited[1][i] == 0){
                countNode[0]++;
            }
            if (i != diff[1] and visited[0][i] == 0 and visited[1][i] == 1){
                countNode[1]++;
            }
        }
        
        // cout << countNode[0] << "*" << countNode[1] << endl;
        cout << countNode[0] * countNode[1];
        cout << endl;
    }
    return 0;
}
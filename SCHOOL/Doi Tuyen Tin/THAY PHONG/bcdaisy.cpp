#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int dp[maxN];
int n, m;
int check[maxN];
vector <int> adj[maxN];
int res;

void DFS(int node){
    // cout << node << endl;
    check[node] = 1;
    for (auto newNode: adj[node]){
        if (check[newNode]){
            continue;
        }
        DFS(newNode);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1);
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            cout << i << " ";
        }
    }
    return 0;
}
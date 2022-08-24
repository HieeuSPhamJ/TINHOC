#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 110;

int n;
int ans = 0;
int a[maxN];
vector <int> adj[6];
int visited[maxN];
int cost[maxN][6];

void init(){
    for (int i = 0; i < maxN; i++){
        visited[i] = 0;
    }
}

void DFS(int node, int sum){
    visited[node]
}



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a,v,b;
        cin >> a >> v >> b;
        a[i] = {a,v,b};
        cost[i][a] = v;
        cost[i][b] = v;
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    for (int i = 1; i <= n; i++){
        init();
        DFS(i, 0);
    }

    cout << ans;

    return 0;
}
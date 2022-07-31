#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, k;
vector <int> adj[maxN];
int f[maxN];
int visited[maxN];
int val[maxN];
vector <ii> lists;


void init(){
    for (int i = 1; i <= n; i++){
        f[i] = 1;
        visited[i] = 0;
    }
}

int DFS(int v){
    // cout << v << endl;
    visited[v] = 1;
    for (auto i: adj[v]){
        if (visited[i] == 0){
            // cout << i << ' ';
            f[v] += DFS(i);
        }
    }
    // cout << endl;
    return f[v];
}

signed main(){
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

    init();
    visited[1] = 1;
    for (auto i: adj[1]){
        // cout << "#" << i << endl;
        f[1] += DFS(i);
    }
    for (int i = 1; i <= n; i++){
        cout << f[i] << endl;
    }
    // cout << endl;
    return 0;
}
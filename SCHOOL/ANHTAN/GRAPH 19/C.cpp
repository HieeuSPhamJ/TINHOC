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
int token[maxN];
vector <ii> lists;


void init(){
    for (int i = 1; i <= n; i++){
        f[i] = 1;
        token[i] = 1;
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
            token[v] += token[i] + f[i];
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
    for (int i = 2; i <= n; i++){
        int inp;
        cin >> inp;
        adj[i].push_back(inp);
        adj[inp].push_back(i); 
    }

    init();
    visited[1] = 1;
    for (auto i: adj[1]){
        // cout << "#" << i << endl;
        f[1] += DFS(i);
        token[1] += f[i] + token[i];
    }
    for (int i = 1; i <= n; i++){
        cout << token[i] << ' ';
    }
    // cout << endl;
    return 0;
}
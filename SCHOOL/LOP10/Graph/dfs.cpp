#include<bits/stdc++.h>
using namespace std;

const int maxN = 2010;

int n, m;
vector <int> adj[maxN];
int visited[maxN] = {0};

void DFS(int Start){
    visited[Start] = 1;
    cout << Start << ' ';
    for (auto i: adj[Start]){
        if (visited[i] == 0){
            DFS(i);
        }
    }
}

int main(){
    freopen("DFS.INP", "r", stdin);
    freopen("DFS.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1);

    return 0;
}
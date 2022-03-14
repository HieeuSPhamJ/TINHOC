#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
vector <int> adj[maxN];
int visited[maxN];

void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        visited[i] = -1;
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

}


void DFS(int )


int main(){
    input();
    DFS();
    output();
    return 0;
}
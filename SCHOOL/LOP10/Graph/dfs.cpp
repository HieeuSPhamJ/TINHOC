#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3;

int e, v;
int Start, End;

vector <int> adj[maxN];
int checkVisited[maxN];

void DFS(int V){
    cout << V << ' ';
    checkVisited[V] = 1;
    for (int i = 0; i < adj[V].size(); i++){
        if (checkVisited[adj[V][i]] != 1){
            DFS(adj[V][i]);
        }
    }


}

int main(){
    cin >> v >> e;
    for (int i = 1; i <= e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> Start >> End;
    DFS(Start);

    return 0;
}
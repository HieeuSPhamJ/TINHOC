#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;

int e, v;
int Start, End;
vector <int> adj[maxN];
queue <int> myQueue;
int visited[maxN];

void input(){
    cin >> v >> e;
    for (int i = 1; i <= e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        visited[i] = -1;
    }
    cin >> Start >> End;
}

void bfs(){
    visited[Start] = 1;
    myQueue.push(Start);
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (int i = 0; i < int(adj[tempV].size()); i++){
                        int newV = adj[tempV][i];
            if (visited[newV] == -1){
                visited[newV] = tempV;
                myQueue.push(newV);
            }
        }
    }
}

void output(){
    for (int i = 1; i <= e; i++){
        cout << visited[i] << endl;
    }
}

int main(){
    input();
    bfs();
    output();
    return 0;
}
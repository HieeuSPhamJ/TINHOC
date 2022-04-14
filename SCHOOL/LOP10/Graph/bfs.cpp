#include<bits/stdc++.h>
using namespace std;

const int maxN = 2010;

int n, m;
vector <int> adj[maxN];
int visited[maxN] = {0};

queue <int> myQueue;

void BFS(int Start){
    myQueue.push(Start);
    visited[Start] = 1;
    cout << Start << ' ';
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visited[i] == 0){
                cout << i << ' ';
                myQueue.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    freopen("BFS.INP", "r", stdin);
    freopen("BFS.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS(1);

    return 0;
}
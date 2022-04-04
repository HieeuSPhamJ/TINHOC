#include<bits/stdc++.h>
using namespace std;

int e,v;
vector <int> adj[100];
int visited[100];
int Start,End;

void inputReader(){
    cin>>v>>e;
    for (int i=1;i<=v;i++){
        visited[i]=-1;
    }
    for (int i=1;i<=e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>Start>>End;

}

void DFS(int start){
    visited[start]=1;
    for (int i=0;i<adj[start].size();i++){
        if (visited[adj[start][i]]==-1){
            DFS(adj[start][i]);
        }
    }
}


int main(){
    inputReader();
    DFS(Start);
    cout<<visited[End];
    return 0;
}
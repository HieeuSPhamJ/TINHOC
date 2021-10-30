#include<bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[10004];
bool visited[10004];
bool checkLoop=0;

void readInput(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int A,B; cin>>A>>B;
        adj[A].push_back(B);
        visited[A]=0;
        visited[B]=0;
    }
}

void DFS(int ver){
    visited[ver]=1;
    for (int i=0;i<int(adj[ver].size());i++){
        int newVer=adj[ver][i];
        if (visited[newVer]==0){
            DFS(newVer);
        }
        else if (visited[newVer]==1){
            checkLoop=true;
        }
    }
}

int main(){
    int test; cin>>test;
    while (test--){
        readInput();
        for (int i=1;i<=n;i++){
            if (visited[i]==0){
                DFS(i);
                // cout<<i;
            }
        }
        if (checkLoop==false) cout<<"NAO";
        else cout<<"SIM";
        cout<<endl;
        checkLoop=true;
    }
}
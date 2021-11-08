#include<bits/stdc++.h>
using namespace std;

int n,m;
pair <int,int> startp;
pair <int,int> endp;
int Maze[30][30];
bool visited[30][30];
int dirX[5]={0,-1,1,0,0};
int dirY[5]={0,0,0,-1,1};


int DFS(pair <int,int> ver){
    int x=ver.first;
    int y=ver.second;
    visited[x][y]==true;
    for (int i=1;i<4;i++){
        int u=ver.first+dirX[i];
        int v=ver.second+dirY[i];
        if (visited[u][v]=false and u<=n and v<=m and u>=1 and v>=1){
            pair <int,int> newVer={x,y};
            return DFS(newVer);
        }
    }
    
}

int main(){
    int test; cin>>test;
    while (test--){
        cin>>m>>n;
        for (int i=1;i<=n;i++){
            for (int e=1;e<=m;e++){
                char inp; cin>>inp;
                if (inp=='.') Maze[i][e]=1;
                else Maze[i][e]=0;
                visited[i][e]=false;
            }
        }
        setUp();
        cout<<endp.first<<' '<<endp.second;
        DFS(startp);
        if (visited[endp.first][endp.second]) cout<<"valid";
        else cout<<"invalid";
        cout<<endl;
    }
}
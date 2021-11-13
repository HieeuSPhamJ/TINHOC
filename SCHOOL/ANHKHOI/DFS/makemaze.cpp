#include<bits/stdc++.h>
using namespace std;

int n,m;
bool Maze[30][30];
bool visited[30][30];
int dirX[5]={0,-1,1,0,0};
int dirY[5]={0,0,0,-1,1};
queue <pair<int,int>> StartAndEnd;


void inputReader(){
    cin>>m>>n;
        for (int i=1;i<=n;i++){
            for (int e=1;e<=m;e++){
                char inp; cin>>inp;
                if (inp=='.') {
                    Maze[i][e]=false;
                    if (e==1 or e==n or i==1 or i==n){
                        StartAndEnd.push(make_pair(i,e));
                    }
                    
                }
                else{
                    Maze[i][e]=true;
                }
                visited[i][e]=false;
            }
        }
}

int checkCount=20;


void check(){
    cout<<"------"<<endl;
    for (int i=1;i<=n;i++){
        for (int e=1;e<=m;e++){
            cout<<visited[i][e]<<' ';
        }
        cout<<endl;
    }
}


void DFS(int x,int y){
    cout<<x<<' '<<y<<endl;
    visited[x][y]==true;
    for (int i=1;i<=4;i++){
        int u=x+dirX[i];
        int v=y+dirY[i];
        // if (visited[u][v]==false and Maze[u][v]==false and u<=n and v<=m and u>=1 and v>=1){
        //     DFS(u,v);
        //     if (checkCount--){
        //         check();
        //     }
        // }
    }
    
}


int main(){
    int test; cin>>test;
    while (test--){
        inputReader();
        // check();
        if (StartAndEnd.size()<=2){
            pair<int,int> Start=StartAndEnd.front();
            StartAndEnd.pop();
            DFS(Start.first,Start.second);
            pair<int,int> End=StartAndEnd.front();
            // cout<<Start.first<<' '<<Start.second<<endl;
            // cout<<End.first<<' '<<End.second<<endl;
            // check();
            if (visited[End.first][End.second]) cout<<"valid";
            else cout<<"invalid";
        }
        else{
            cout<<"valid";
        }
        
        cout<<endl;
    }
}
/*
1
4 4
####
#...
#.##
#.##
*/
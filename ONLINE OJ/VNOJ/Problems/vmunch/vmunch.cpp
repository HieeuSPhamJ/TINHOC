#include<bits/stdc++.h>
using namespace std;

int N,M;
bool field[102][102];
int visited[102][102];
queue <pair<int,int>> myQueue;
int dirX[5]={0,-1,1,0,0};
int dirY[5]={0,0,0,-1,1};
pair <int,int> Start;
pair <int,int> End;
int check=30;

void inputReader(){
    cin>>N>>M;
    for (int i=1;i<=N;i++){
        for (int e=1;e<=M;e++){
            char inp;
            cin>>inp;
            if (inp=='B'){
                Start=make_pair(i,e);
                visited[i][e]=0;
            }
            else if (inp=='C'){
                End=make_pair(i,e);
                visited[i][e]=0;
            }
            else if (inp=='*'){
                field[i][e]=1;
                visited[i][e]=1;
            }
            else {
                field[i][e]=0;
                visited[i][e]=0;
            }
        }
    }
}

void outputWriter(){
    cout<<visited[End.first][End.second]<<endl;
    // for (int x=1;x<=N;x++){
    //     for (int y=1;y<=M;y++){
    //         cout<<visited[x][y]<<' ';
    //     }
    //     cout<<endl;
    // }
    //  cout<<End.first<<' '<<End.second;

}

void BFS(){
    myQueue.push(make_pair(Start.first,Start.second));
    visited[Start.first][Start.second]=0;
    while (!myQueue.empty()){
        pair <int,int> tempV=myQueue.front();
        myQueue.pop();
        for (int i=1;i<=4;i++){
            int x=tempV.first+dirX[i];
            int y=tempV.second+dirY[i];
            if (x>=1 and x<=N and y>=1 and y<=M and visited[x][y]==0 and field[x][y]==0){
                myQueue.push(make_pair(x,y));
                visited[x][y]=visited[tempV.first][tempV.second]+1;
                if (check--){
                    // outputWriter();
                }
            }
        }
    }
}


int main(){
    inputReader();
    BFS();
    outputWriter();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxN = 102;

int N, M;
int maze[maxN][maxN];
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
pair<int,int> Start, End;
queue <pair <int, int> > myQueue;

void inputReader(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int e = 1; e <= M; e++){
            char inp;
            cin >> inp;
            if (inp == 'B'){
                Start = {i, e};
            }
            else if (inp == 'C'){
                End = {i, e};
            }
            else if (inp == '.'){
                maze[i][e] = 0;
            }
            else if (inp == '*'){
                maze[i][e] = 1;
            }
        }
    }
}

void outputWriter(){
    for (int i = 1; i <= N; i++){
        for (int e = 1; e <= M; e++){
            cout << maze[i][e];
        }
        cout << endl;
    }
}

void BFS(){
    myQueue.push(make_pair(Start.first, Start.second));
    maze[Start.first][Start.second] = 1;
    while(!myQueue.empty()){
        pair <int, int> tempV = myQueue.front();
        myQueue.pop();
        // cout << "# " << tempV.first << ' ' << tempV.second << endl;
        for (int i = 0; i < 4; i++){
            pair <int, int> newV = make_pair(tempV.first + dirx[i], tempV.second + diry[i]);
            if (newV.first > 0 and newV.second > 0 and newV.first <= N and newV.second <= M and maze[newV.first][newV.second] == 0){
                // cout << newV.first << ' ' << newV.second << endl;
                myQueue.push(newV);
                maze[newV.first][newV.second] = maze[tempV.first][tempV.second] + 1;
                // outputWriter();
                // cout << endl;
            }
        }
    }
}



int main(){
    inputReader();
    BFS();
    // outputWriter();
    cout << maze[End.first][End.second] - 1;
    return 0;
}
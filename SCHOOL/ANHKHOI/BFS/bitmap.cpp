#include<bits/stdc++.h>
using namespace std;


int n, m;
int maze[200][200];
int visited[200][200];
queue <pair <int, int>> myQueue;
int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {-1, 1, 0 ,0};

bool checkCan(int x, int y){
    if (1 <= x and 1 <= y and x <= n and y <= m and maze[x][y] == 0){
        return true;
    }
    return false;
}

void BFS(){
    while(!myQueue.empty()){
        pair <int, int> tempV = myQueue.front();
        myQueue.pop();
        for (int i = 0; i < 4; i++){
            pair <int, int> newV = make_pair( tempV.first + dirX[i], tempV.second + dirY[i]);
            if (checkCan(newV.first, newV.second)){
                myQueue.push(newV);
                visited[newV.first][newV.second] = visited[tempV.first][tempV.second] + 1;
                maze[newV.first][newV.second] = 1;
            }
        }

    }
}


int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            for (int e = 1; e <= m; e++){
                maze[i][e] = s[e - 1] - '0';
                if (maze[i][e] == 1){
                myQueue.push(make_pair(i, e));
            }
            visited[i][e] = 0;
            }
            
        }
        BFS();
        for (int i = 1; i <= n; i++){
            for (int e = 1; e <= m; e++){
                cout << visited[i][e] << ' ';
            }
            cout << endl;
        }
        
    }
    return 0;
}
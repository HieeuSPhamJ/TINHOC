#include<bits/stdc++.h>
using namespace std;

int maze[100][100];
long long n, m, c, k;
int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {-1, 1, 0 ,0};
long long countAns = 0;
int lastX = 1;
int lastY = 1;

void clearMaze(){
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            maze[i][j] = 0;
        }
    }
}

void printMaze(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------" << endl;
    
}

void backTracking(int index){
    printMaze();
    if (index > c){
        long long count = 0;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         int check = 0;
        //         for (int x = 0; x < 4; x++){
        //             if (maze[i + dirX[x]][j + dirY[x]] == 1){
        //                 check++;
        //             }
        //         }
        //         if (check == 0){
        //             count++;
        //         }
        //     }
        // }
        if (count <= k){
            countAns++;
        }
        // cout << lastX << ' ' << lastY << endl;
        return;
    }
    for (int i = lastX; i <= n; i++){
        for (int j = lastY; j <= m; j++){
            if (maze[i][j] == 0){
                maze[i][j] = 1;
                backTracking(index + 1);
                maze[i][j] = 0;
            }

        }
    }
    clearMaze();
    if (lastX + 1 <= n){
        lastX++;
    }
    else{
        lastX = 1;
        lastY++;
    }
}

int main(){
    // freopen("SC5.INP", "r", stdin);
    // freopen("SC5.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        countAns = 0;
        cin >> n >> m >> c >> k;
        backTracking(1);
        cout << countAns;
        cout << endl;
    }

    return 0;
}
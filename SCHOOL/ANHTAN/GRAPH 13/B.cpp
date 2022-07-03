#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 110;

struct iii{
    int x;
    int y;
    int dir;
    iii(int a, int b, int c){
        x = a;
        y = b;
        dir = c;
    }
};

int n, m;
int a[maxN][maxN];
int visited[maxN][maxN];
int turn[maxN][maxN][4];
queue <iii> myQueue;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

void print(){
    cout << "--$--" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (visited[i][j]  == 1e9){
                cout << "*" << ' ';
            }
            else cout << visited[i][j] << ' ';

        }
        cout << endl;
    }
    cout << "-----" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            visited[i][j] = 0;
        }
    }

    visited[1][1] = 1;
    if (a[1][2] == 0){
        myQueue.push({1, 2, 3});
        visited[1][2] = 2;
        turn[1][2][3] = 1;
    }
    if (a[2][1] == 0){
    myQueue.push({2, 1, 2});
        visited[2][1] = 2;
    turn[2][1][2] = 1;
    }

    int q, g;
    cin >> q >> g;

    while (!myQueue.empty()){
        iii tempV = myQueue.front();
        myQueue.pop();
        
        // cout << tempV.x << ' ' << tempV.y << ' ' << tempV.dir << endl;
        for (int j = 0; j <= 1; j++){
            int newDir = (tempV.dir + j) % 4;
            iii newV(tempV.x + dirX[newDir], tempV.y + dirY[newDir], newDir);
            if (newV.x <= n and newV.x >= 1 and newV.y <= m and newV.y >= 1 and a[newV.x][newV.y] != 1){
                if (turn[newV.x][newV.y][newDir] == 0){
                    turn[newV.x][newV.y][newDir] = 1;
                    // cout << newV.x << ' ' << newV.y << endl;
                    // cout << a[newV.x][newV.y] << endl;
                    visited[newV.x][newV.y] = visited[tempV.x][tempV.y] + 1;
                    myQueue.push({newV.x, newV.y, newV.dir});
                    if (newV.x == q and newV.y == g){
                        cout << visited[newV.x][newV.y];
                        exit(0);
                    }
                    // print();
                }
            }
        }

        // cout << endl;

    }

    
    cout << 0;

    
    

    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

struct iii{
    int x,y,jump;
};

const int maxN = 600;
int a[maxN][maxN];
int visited[3][maxN][maxN];

int dirX[] = {0,0,1,-1,0,0,2,-2};
int dirY[] = {1,-1,0,0,2,-2,0,0};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        int n, k;
        cin >> n >> k;
        ii s, e;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                visited[0][i][j] = visited[1][i][j] = -1;
                char inp;
                cin >> inp;
                if (inp == 'K'){
                    s = {i,j};
                }
                else if (inp == 'S'){
                    e = {i,j};
                }
                else if (inp == '*'){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = 0;
                }
            }
        }

        queue <iii> myQueue;
        myQueue.push({s.f, s.s, 0});
        visited[0][s.f][s.s] = 0;
        
        while(!myQueue.empty()){
            iii tempV = myQueue.front();
            myQueue.pop();
            for (int i = 0; i < 8; i++){
                int newX = tempV.x + dirX[i];
                int newY = tempV.y + dirY[i];
                if (abs(dirX[i]) > 1 or abs(dirY[i]) > 1){
                    if (newX >= 1 and newX <= n and newY >= 1 and newY <= n and a[newX][newY] == 0){
                        if (tempV.jump == 0 and and visited[1][newX][newY] == -1){
                            visited[1][newX][newY] = visited[0][tempV.x][tempV.y] + 1;
                            myQueue.push({newX, newY, 1});
                        }
                    }
                }
                else{
                    if (newX >= 1 and newX <= n and newY >= 1 and newY <= n and a[newX][newY] == 0){
                        visited[tempV.jump][newX][newY] = visited[0][tempV.x][tempV.y] + 1;
                        myQueue.push({newX, newY, tempV.jump});
                    }
                }
            }
        }

        if (max(visited[0][e.f][e.s], visited[1][e.f][e.s]) >= 0){
            cout << min(visited[0][e.f][e.s], visited[1][e.f][e.s]);
        }
        else{
            cout << -1;
        }

        cout << endl;

    }

    return 0;
}
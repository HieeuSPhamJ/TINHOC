#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define int long long
using namespace std;

const int maxN = 2010 + 10;

int n, m, k;
int visited1[maxN][maxN];
int visitedn[maxN][maxN];
int a[maxN][maxN];
int dirX[] = {0,0,1,-1};
int dirY[] = {1,-1,0,0};
vector <ii> lists;
vector <ii> listPortal;


void resetVi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited1[i][j] = -1;
            visitedn[i][j] = -1;
        }
    }
}
void print(ii n){
    cout << n.x << '-' << n.y;
}
bool checkX(int x){
    if (x >= 1 and x <= n){
        return 1;
    }
    return 0;
}
bool checkY(int x){
    if (x >= 1 and x <= m){
        return 1;
    }
    return 0;
}

void BFS(ii Start, ii End){
    resetVi();
    queue <ii> myQueue;
    visited1[Start.x][Start.y] = 0;
    myQueue.push(Start);
    while(!myQueue.empty()){
        ii tempV = myQueue.front();
        myQueue.pop();
        // print(tempV);
        // cout << endl;
        for (int i = 0; i < 4; i++){
            int newX = tempV.x + dirX[i];
            int newY = tempV.y + dirY[i];

            if (checkX(newX) and checkY(newY) and visited1[newX][newY] == -1 and a[newX][newY] != -1){
                visited1[newX][newY] = visited1[tempV.x][tempV.y] + k;
                myQueue.push({newX, newY});
                // cout << newX << '-' << newY << "  ";
            }
        }
        // cout << endl;
    }

    visitedn[End.x][End.y] = 0;
    myQueue.push(End);
    while(!myQueue.empty()){
        ii tempV = myQueue.front();
        myQueue.pop();
        // print(tempV);
        // cout << endl;
        for (int i = 0; i < 4; i++){
            int newX = tempV.x + dirX[i];
            int newY = tempV.y + dirY[i];

            if (checkX(newX) and checkY(newY) and visitedn[newX][newY] == -1 and a[newX][newY] != -1){
                visitedn[newX][newY] = visitedn[tempV.x][tempV.y] + k;
                myQueue.push({newX, newY});
                // cout << newX << '-' << newY << "  ";
            }
        }
        // cout << endl;
    }
    
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        cin >> n >> m >> k;
        // cout << n << ' ' << k << endl;
        ii s, e;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                if (a[i][j] > 0){
                    listPortal.push_back({i, j});
                }
            }
        }

        BFS({1, 1}, {n, m});

        int ans = 1e18;

        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << visited1[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << visitedn[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int ans1 = 1e18;
        int ans2 = 1e18;

        for (auto i: listPortal){
            ans1 = min(ans1, a[i.x][i.y] + visited1[i.x][i.y]);
            ans2 = min(ans2, a[i.x][i.y] + visitedn[i.x][i.y]);
            
        }

        ans = min(ans, ans1 + ans2);

        if (visited1[n][m] != -1){
            ans = min(ans, visited1[n][m]);
        }
        if (ans == 1e18){
            cout << -1;
            return 0;
        }
        cout << ans;

    return 0;
}
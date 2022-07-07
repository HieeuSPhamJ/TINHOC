#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define ll long long
using namespace std;

const int maxN = 500 + 10;

struct iiii{
    int x1,y1,x2,y2;
};

int n, k;
int visited1[maxN][maxN];
int visitedn[maxN][maxN];
int a[maxN][maxN];
int dirX[] = {0,0,1,-1};
int dirY[] = {1,-1,0,0};
iiii dirList[] = {
    {1,0,-1,0},
    {0,1,0,-1}
};

vector <ii> lists;


void resetVi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited1[i][j] = -1;
            visitedn[i][j] = -1;
        }
    }
}

void print(ii n){
    cout << n.x << '-' << n.y;
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

            if (newX >= 1 and newX <= n and newY >= 1 and newY <= n and visited1[newX][newY] == -1 and a[newX][newY] != 1){
                visited1[newX][newY] = visited1[tempV.x][tempV.y] + 1;
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

            if (newX >= 1 and newX <= n and newY >= 1 and newY <= n and visitedn[newX][newY] == -1 and a[newX][newY] != 1){
                visitedn[newX][newY] = visitedn[tempV.x][tempV.y] + 1;
                myQueue.push({newX, newY});
                // cout << newX << '-' << newY << "  ";
            }
        }
        // cout << endl;
    }
    
}

bool check(int x){
    if (x >= 1 and x <= n){
        return 1;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while(test--){
        lists.clear();
        cin >> n >> k;
        // cout << n << ' ' << k << endl;
        ii s, e;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char inp;
                cin >> inp;
                if (inp == 'K'){
                    s = {i,j};
                    a[i][j] = 0;
                }
                else if (inp == 'S'){
                    e = {i,j};
                    a[i][j] = 0;
                }
                else if (inp == '*'){
                    a[i][j] = 1;
                    lists.push_back({i,j});
                }
                else {
                    a[i][j] = 0;
                }
            }
        }

        // print(s);
        // cout << ' ';
        // print(e);
        // cout << endl;

        BFS(s, e);

        int ans1 = visited1[e.x][e.y];

        if (k == 0){
            cout << ans1 << endl;
            continue;
        }

        int ans2 = 1e9;

        
        
        for (auto i: lists){
            for (auto dir: dirList){
                int newX1 = i.x + dir.x1;
                int newY1 = i.y + dir.y1;
                int newX2 = i.x + dir.x2;
                int newY2 = i.y + dir.y2;

                if (a[newX1][newY1] == 0 and a[newX2][newY2] == 0 and check(newX1) and check(newX2) and check(newY1) and check(newY2)){
                    // cout << newX1 << "-" << newY1 << " " << newX2 << "-" << newY2 << endl;
                    int temp1 = visited1[newX1][newY1];
                    int temp2 = visitedn[newX2][newY2];

                    // cout << temp1 << ' ' << temp2 << endl;

                    if (temp1 >= 0 and temp2 >= 0){
                        ans2 = min(ans2, temp1 + temp2 + 1);
                    }

                    temp1 = visited1[newX2][newY2];
                    temp2 = visitedn[newX1][newY1];
                    
                    // cout << temp1 << ' ' << temp2 << endl;
                    if (temp1 >= 0 and temp2 >= 0){
                        ans2 = min(ans2, temp1 + temp2 + 1);
                    }
                }
            }
        }
        if (ans2 == 1e9){
            ans2 = -1;
        }
        if (ans1 >= 0 and ans2 >= 0){
            cout << min(ans1, ans2);
            cout << endl;
            continue;
        }

        cout << max(ans1, ans2);
        cout << endl;
    }

    return 0;
}
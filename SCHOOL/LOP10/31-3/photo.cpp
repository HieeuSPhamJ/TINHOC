#include<bits/stdc++.h>
using namespace std;

const int maxN = 111;

int maze[maxN][maxN];

int countK(int Ax, int Ay, int Bx, int By){
    int count = 0;
    for (int i = Ax; i <= Bx; i++){
        for (int j = Ay; j <= By; j++){
            count += maze[i][j];
        }
    }
    return count;
}

int main(){
    freopen("photo.INP", "r", stdin);
    freopen("photo.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    int na, k;
    cin >> na >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            maze[i][j] = 0;
        }
    }
    for (int i = 1; i <= na; i++){
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    int countAns = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int x = 1; x <= n; x++){
                for (int y = 1; y <= m; y++){
                    int temp = countK(i,j,x,y);
                    if (temp >= k){
                        countAns++;
                    }
                }
            }
        }
    }
    cout << countAns;

    return 0;
}
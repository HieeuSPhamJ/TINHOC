#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 110;

int n, m, k;
int dir[maxN][maxN];
ii boss[maxN][maxN];
int sizeCom[maxN][maxN];
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

ii getBoss(ii node){
    if (node == boss[node.f][node.s]){
        return node;
    }
    return boss[node.f][node.s] = getBoss(boss[node.f][node.s]);
}

void printBoss(){
    cout << "-boss-" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << "[" << boss[i][j].f << "," << boss[i][j].s << "] ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

void printSize(){
    cout << "-size-" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << sizeCom[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------" << endl;
}

void printLake(){
    cout << "-lake-" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << dir[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------" << endl;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            boss[i][j] = {i, j};
            sizeCom[i][j] = 1;
        }
    }
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        dir[a][b] = 1;
    }

    // printLake();
    // printBoss();
    // printSize();

    int maxCom = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (dir[i][j] != 1){
                continue;
            }
            for (int x = 0; x < 4; x++){
                int newI = i + dirX[x];
                int newJ = j + dirY[x];

                ii u = getBoss({i, j});
                ii v = getBoss({newI, newJ});
                
                if (dir[newI][newJ] == 1){
                    if (u == v){
                        continue;
                    }
                    boss[v.f][v.s] = u;
                    sizeCom[u.f][u.s] += sizeCom[v.f][v.s];

                    maxCom = max(maxCom, sizeCom[u.f][u.s]);

                    // cout << i << ' ' << j << ' ' << newI << ' ' << newJ << endl;
                    // printBoss();
                    // printSize();
                }
            }
        }
    }

    cout << maxCom;





    
    

    return 0;
}
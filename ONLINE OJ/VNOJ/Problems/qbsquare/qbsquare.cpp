#include<bits/stdc++.h>
using namespace std;

int n , m;
int maze[1010][1010];


int main(){
    cin >> n >> m;
    for (int i = 0; i <= 1005; i++){
        for (int e = 0; e <= 1005; e++){
            maze[i][e] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int e = 1; e <= m; e++){
            cin >> maze[i][e];
            maze[i][e] += - maze[i - 1][e - 1] + maze[i][e - 1] + maze[i - 1][e];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int e = 1; e <= m; e++){
            if (maze[i][e] < 10){
                cout << 0;
            }
            cout << maze[i][e] << ' ';
        }
        cout << endl;
    }



    return 0;
}
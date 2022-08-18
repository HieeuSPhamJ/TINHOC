#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int a[10][10];
int matrix[4][4][4][4];

int dp[4][(1 << 3)][9][4][4][4][4][4][4];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            char inp;
            cin >> inp;
            matrix[i / 3][j / 3][i % 3][j % 3] = inp - '0';

        }
    }

    // for (int x = 0; x < 3; x++){
    //     for (int y = 0; y < 3; y++){
    //         cout << x << ":" << y << endl;
    //         for (int i = 0; i < 3; i++){
    //             for (int j = 0; j < 3; j++){
    //                 cout << matrix[x][y][i][j] << " ";
    //             }
    //             cout << endl;   
    //         }
    //     }
    // }

    

    





    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int d, n;
        cin >> d >> n;
        d = 15;
        char maze[51][51];
        for (int i = 1; i <= d; i++){
            for (int j = 1; j <= d; j++){
                maze[i][j] = 'A';
            }
        }
        // for (int i = 1; i <= d; i++){
        //     for (int j = 1; j <= d; j += 4){
        //         maze[i][j] = 'A';
        //     }
        // }
        for (int i = 1; i <= d; i++){
            for (int j = 3; j <= d; j += 4){
                maze[i][j] = 'C';
            }
        }
        for (int i = 2; i <= d; i++){
            for (int j = 2; j <= d; j += 2){
                if (n >= 3){
                    maze[i][j] = 'B';
                    n -= 3;
                }
            }
        }
        for (int i = 2; i <= d; i += 2){
            if (n > 0){
                maze[1][i] = 'B';
                n--;
            }
            if (n > 0){
                maze[d][i] = 'B';
                n--;
            }
        }

        cout << d << ' ' << d << endl; 
        for (int i = 1; i <= d; i++){
            for (int j = 1; j <= d; j++){
                cout << maze[i][j];
            }
            cout << endl;
        }
        // cout << endl;
    }

    return 0;
}
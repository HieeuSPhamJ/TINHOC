#include<bits/stdc++.h>
using namespace std;

int a[130][130];
int dp[130][130];
int dp2[130][130];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char inp;
            cin >> inp;
            if (inp == '*'){
                a[i][j] = 1;
            }
            else if (inp == '#'){
                a[i][j] = - 1e9;
            }
            else {
                a[i][j] = 0; 
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
            if (a[i][j] != -1){
                if (a[i + 1][j] > a[i][j + 1] and a[i + 1][j] != -1e9){
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = 0;
                }
                else if (a[i + 1][j] <= a[i][j + 1] and a[i][j + 1] != -1e9){
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = 0;
                }
            }
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
            if (a[i][j] != -1){
                if (a[i + 1][j] > a[i][j + 1] and a[i + 1][j] != -1e9){
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = 0;
                }
                else if (a[i + 1][j] <= a[i][j + 1] and a[i][j + 1] != -1e9){
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = 0;
                }
            }
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }
    

    return 0;
}
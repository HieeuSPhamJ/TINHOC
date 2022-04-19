#include<bits/stdc++.h>
using namespace std;

int dp[130][130];
int dp2[130][130];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; i++){
            char inp;
            cin >> inp;
            if (inp == '*'){
                a[i][j] = 1;
            }
            else if (inp == '#'){
                a[i][j] = - 1e9;
            }
            a[i][j] = 0; 
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
            if (a[i][j] != -1){
                a[i][j] 
            }
        }
    }
    

    return 0;
}
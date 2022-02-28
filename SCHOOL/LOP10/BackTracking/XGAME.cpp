#include<bits/stdc++.h>
using namespace std;

int m, n;
int countP = 0;
bool check[100] = {0};
int tempSum;
map <string, bool> mapCheck;


void backTracking(int index){
    // cout << '#' << endl;
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            check[i] = 1;
            tempSum += i;
            backTracking(index + 1);
            if (tempSum == m){
                countP++;
            }
            tempSum -= i;
            check[i] = 0;
        }
    }
}

int main(){
    freopen("XGAME.INP", "r", stdin);
    freopen("XGAME.OUT", "w", stdout);
    
    cin >> n >> m;
    backTracking(1);
    cout << countP;
    return 0;
}
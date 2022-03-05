#include<bits/stdc++.h>
using namespace std;
 
int n, p, k;
int ax[60][30];
int ans = 0;
void backTracking(int sum, int turn, int a, int b, int c){
    if (turn <= 0){
        return;
    }
    ans = max(sum, ans);
    backTracking(sum + ax[1])

}

int main(){
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            cin >> ax[i][j];
        }
    }   
    backTracking(0, p, k, k, k);
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
int n;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
long long ans = 1e18+10;

void backTracking(int d, long long temp, int nx){
    // cout << temp << endl;
    if(nx > n or d >= 16){
        return;
    }
    if(nx == n and temp < ans) {
        ans = temp;
    }
    for(int i = 1; i <= 70; i++){
        if(ans < temp) {
            break;
        }
        backTracking(d+1, temp *= p[d], nx*(i+1));
    }
}

int main(){
    cin >> n;
    backTracking(0, 1, 1);
    cout << ans << endl;
    return 0;
}
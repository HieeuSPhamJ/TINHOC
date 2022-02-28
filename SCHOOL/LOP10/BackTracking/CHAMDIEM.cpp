#include<bits/stdc++.h>
using namespace std;

int n;
int countP = 0;

void backTracking(int i, int s){
    if (s == n){
        countP++;
        return;
    }
    if (s > n){
        return;

    }
    backTracking(i + 1, s + 1);
    backTracking(i + 1, s + 2);
    backTracking(i + 1, s + 3);

}


int main(){
    freopen("CHAMDIEM.INP", "r", stdin);
    freopen("CHAMDIEM.OUT", "w", stdout);
    
    cin >> n;
    backTracking(0, 0);
    cout << countP;
    return 0;
}
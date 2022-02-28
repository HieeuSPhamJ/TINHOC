#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000];
int countP = 0;

void backTracking(int i, int sum){
    // cout << sum << endl;
    if (sum == m){
        countP++;
        return;
    }
    if (sum > m or i > n){
        return;
    }
    backTracking(i + 1, sum);
    backTracking(i + 1, sum + a[i]);
}

int main(){
    freopen("MONEY.INP", "r",stdin);
    freopen("MONEY.OUT", "w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backTracking(1, 0);
    cout << countP;
    return 0;
}
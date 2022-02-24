#include<bits/stdc++.h>
using namespace std;

int n;
long long a[20];
long long minx = 1e18;

void BackTracking(int index, long long ax, long long bx, long long cx){
    // cout << '#' << index - 1 << "|" << ax << ' ' << bx << ' ' << cx << endl;
    if (index == n + 1){
        minx = min(minx, max({ax, bx, cx}) - min({ax, bx, cx}));
        return;
    }
    BackTracking(index + 1, ax + a[index], bx, cx);
    BackTracking(index + 1, ax, bx + a[index], cx);
    BackTracking(index + 1, ax, bx, cx + a[index]);
    
}

int main(){
    freopen("CHIAQUA.INP", "r", stdin);
    freopen("CHIAQUA.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    BackTracking(0, 0, 0, 0);
    cout << minx;
    return 0;
}
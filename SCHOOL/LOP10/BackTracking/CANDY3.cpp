#include <bits/stdc++.h>
using namespace std;

const int maxN = 20;

int n;
int a[maxN];
int ans = 1e8;

void backTracking(int index, int sum1, int sum2, int sum3){
    // cout << sum1 << ' ' << sum2 << ' ' << sum3 << endl;
    if (index > n){
        // cout << index << endl;
        ans = min(ans, max({sum1, sum2, sum3}) - min({sum1, sum2, sum3}));
        return;
    }
    backTracking(index + 1, sum1 + a[index], sum2, sum3);
    backTracking(index + 1, sum1, sum2 + a[index], sum3);
    backTracking(index + 1, sum1, sum2, sum3 + a[index]);
    

}

int main(){
    freopen("CANDY3.INP", "r", stdin);
    freopen("CANDY3.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backTracking(1, 0, 0 ,0);
    cout << ans;
    return 0;
}
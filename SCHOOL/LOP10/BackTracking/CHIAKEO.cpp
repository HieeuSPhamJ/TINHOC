#include<bits/stdc++.h>
using namespace std;

const int maxN = 30;
int ans = 0;
int n;
int a[maxN];

void Backtracking(int index, int tempans, int sum){
    ans = min(ans, abs(tempans - sum));
    if (index < n){
        Backtracking(index + 1, tempans, sum);
        Backtracking(index + 1, tempans + a[index], sum - a[index]);
    }

}

int main(){
    freopen("CHIAKEO.INP", "r", stdin);
    freopen("CHIAKEO.OUT", "w", stdout);    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i];
    }
    Backtracking(1, 0, ans);
    cout << ans;
    return 0;
}
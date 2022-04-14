#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("Tennis.INP", "r", stdin);
    freopen("Tennis.OUT", "w", stdout);
    long long k, a, b;
    cin >> k >> a >> b;
    int ans = a / k + b / k;
    // cout << ans << ' ' << (a % k > 0 and b % k > 0) << endl;
    if (ans == 0 or (ans == 1 and (a % k > 0 and b % k > 0))){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 2 * 1e5 + 10;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            ans = max(ans, (i - j) * j);
        }
    }
    cout << ans;
    return 0;
}
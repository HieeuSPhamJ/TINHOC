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
    int n, k;
    cin >> n >> k;
    int m = 1e18;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        m = min(inp, m);
        sum += inp;
    }

    k -= sum;
    int ans = n;

    ans += k / m;

    cout << ans;
    return 0;
}
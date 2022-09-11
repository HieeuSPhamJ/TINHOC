#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 * 2 + 10;
int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;

    for (int i = n, temp = 1e18; i >= 1; i--){
        ans += min(a[i], temp);
        // cout << min(a[i], temp) << " ";
        temp = max(0ll, (min(a[i], temp) - 1));
    }
    // cout << endl;
    cout << ans;

    return 0;
}
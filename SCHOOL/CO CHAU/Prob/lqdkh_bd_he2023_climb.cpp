#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    freopen("climb.INP", "r", stdin);
    freopen("clim.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum1 = 0;
    int sum2 = 0;
    int magaming1 = 1e18;
    int magaming2 = 1e18;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        sum1 += a;
        sum2 += b;
        magaming1 = min(magaming1, a);
        magaming2 = min(magaming2, b);
    }

    // cout << sum1 << " " << sum2 << " " << magaming1 << " " << magaming2 << endl;

    cout << max(sum1 + magaming2, sum2 + magaming1);
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d, p;
    cin >> n >> d >> p;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        a[i] += a[i - 1];
    }

    int res = 1e18;
    for (int i = 0; (i - 1) * d <= n; i++){
        int t = max(0ll, n - i * d);
        res = min(res, a[t] + i * p);
    }
    cout << res << endl;
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

ii x[maxN];
int k[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++){
        cin >> x[i].fi >> x[i].se >> k[i];
    }
    for (int t = 1; t <= 3; t++){
        int a[4];
        int tres = 0;
        // cout << "TEST: " << t << endl;
        memset(a, 0, sizeof(a));
        a[t] = 1;
        // for (int j = 1; j <= 3; j++){
        //     cout << a[j] << ' ';
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++){
            swap(a[x[i].fi],a[x[i].se]);
            // for (int j = 1; j <= 3; j++){
            //     cout << a[j] << ' ';
            // }
            // cout << endl;
            tres += a[k[i]];
        }
        res = max(res,tres);
    }

    cout << res << endl;

    return 0;
}
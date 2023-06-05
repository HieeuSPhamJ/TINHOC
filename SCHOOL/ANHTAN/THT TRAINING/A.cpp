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

int n,m;
int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    double res = -1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[0] = -a[1];
    a[n + 1] = m + (m - a[n]);

    for (int i = 1; i <= n + 1; i++){
        res = max(res, (double)(a[i] - a[i - 1]) / 2);
        // cout << (double)(a[i] - a[i - 1]) / 2 << endl;
    }

    if (abs(res - (int)(res)) <= 1e-6){
        cout << (int)res << endl;
        return 0;
    }

    cout << fixed << setprecision(1) << res << endl;

    return 0;
}
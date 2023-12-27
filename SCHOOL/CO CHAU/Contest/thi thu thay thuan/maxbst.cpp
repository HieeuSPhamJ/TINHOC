#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

namespace sub14{
    const int maxN = 1e6 + 10;

    ii child[maxN];
    int a[maxN];

    int dfs(int nu, int lv = 0, int rv = 1e18){
        if (nu == 0){
            return 0;
        }
        int res = 0;
        if (lv <= a[nu] and a[nu] <= rv){
            res++;
            res += dfs(child[nu].fi, lv, a[nu] - 1);
            res += dfs(child[nu].se, a[nu] + 1, rv);
        }
        return res;
    }

    void solve(){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            child[i] = {0,0};
        }
        for (int i = 1; i <= n; i++){
            cin >> child[i].fi >> child[i].se >> a[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            int tres = dfs(i);
            res = max(res, tres);
        }

        cout << res << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("maxbst.inp", "r")) {
        freopen("maxbst.inp", "r", stdin);
        freopen("maxbst.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sub;
    cin >> sub;
    sub14::solve();
    return 0;
}
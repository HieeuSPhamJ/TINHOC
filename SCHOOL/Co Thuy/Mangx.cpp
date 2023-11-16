#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

ii pre[maxN];
ii suf[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("mangx.inp", "r")) {
        freopen("mangx.inp", "r", stdin);
        freopen("mangx.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    sort(all(ls));
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    int res = ls.back() - ls.front();
    pre[0] = {-1e18,1e18};
    suf[n + 1] = {-1e18,1e18};
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        pre[i].fi = max(pre[i].fi, ls[i - 1] + k);
        pre[i].se = min(pre[i].se, ls[i - 1] + k);
    }
    for (int i = n; i >= 1; i--){
        suf[i] = suf[i + 1];
        suf[i].fi = max(suf[i].fi, ls[i - 1] - k);
        suf[i].se = min(suf[i].se, ls[i - 1] - k);
    }
    
    for (int i = 1; i < n; i++){
        res = min(res, max(pre[i - 1].fi, suf[i].fi) - min(pre[i - 1].se, suf[i].se));
    }
    cout << res << endl;
    return 0;
}
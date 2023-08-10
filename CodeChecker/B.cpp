#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n;
ii a[1000000];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {u - v, u + v};
    }
    sort(a + 1, a + 1 + n);
    int l = -1, r = -1, ans = n;
    for(int i = 1; i <= n; i++) {
        if(a[i].fi >= r) {
            l = a[i].fi;
            r = a[i].se;
            continue;
        }
        if(a[i].fi == l) {
            ans--;
            r = max(a[i].se, r);
        }
        else if(a[i].se <= r) {
            ans--;
        }
        else {
            l = a[i].fi;
            r = a[i].se;
        }
    }
    cout << ans;
    return 0;
}
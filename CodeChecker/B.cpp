#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
using namespace std;

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    int n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;
    vector<tuple<int, int, int>> ev;
    vector<int> bm;
    for (int i = 1; i <= n; i++) {
        int m = a * i % b;
        int l = a * i + b;
        int r = a * i + b * n;
        ev.emplace_back(l, m, 1);
        ev.emplace_back(r+1, m, -1);
        bm.emplace_back(m);
    }
    sort(ev.begin(), ev.end());
    sort(bm.begin(), bm.end());
    bm.erase(unique(bm.begin(), bm.end()), bm.end());
    vector<int> cnt(SZ(bm), 0);
    int t = 0;
    int ans = 0;
    for (int k = n; k >= 1; k--) {
        int y = x - k * c;
        while (t < SZ(ev) && get<0>(ev[t]) <= y) {
            int m = get<1>(ev[t]);
            m = lower_bound(bm.begin(), bm.end(), m) - bm.begin();
            cnt[m] += get<2>(ev[t]);
            t++;
        }
        int m = lower_bound(bm.begin(), bm.end(), y % b) - bm.begin();
        if (m < SZ(cnt) && bm[m] == y % b)
            ans += cnt[m];
    }
    cout << ans << "\n";
    return 0;
}

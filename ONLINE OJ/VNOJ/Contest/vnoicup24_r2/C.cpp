#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;

int n;
ii a[maxN];
ii pre[maxN];
int last = 1;

ii sum(int l, int r) {
    ii x = pre[r];
    if (l > 1) {
        x.fi -= pre[l - 1].fi;
        x.se -= pre[l - 1].se;
    }
    return x;
}

int cal(int x, int l = 1, int r = n) {
    int lo = l, hi = r, i = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].fi <= x) {
            i = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    int res = 0;
    if (i > 0) {
        ii s = sum(1, i);
        res += s.se * x - s.fi;
    }
    if (i < n) {
        ii s = sum(i + 1, n);
        res += s.fi - s.se * x;
    }
    return res;
}

signed main() {
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while (test--) {
        last = 1;
        cin >> n;
        int MIN = 1e18, MAX = -1e18;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].fi;
            MIN = min(MIN, a[i].fi);
            MAX = max(MAX, a[i].fi);
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i].se;
        }
        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i++) {
            pre[i].fi = pre[i - 1].fi + a[i].fi * a[i].se;
            pre[i].se = pre[i - 1].se + a[i].se;
        }

        int res = 1e18;
        for (int x = MIN; x <= MAX; x++) {
            res = min(res, cal(x, last, n));
        }

        if (res > cal(-1e6 - 1)) {
            cout << "-inf" << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}

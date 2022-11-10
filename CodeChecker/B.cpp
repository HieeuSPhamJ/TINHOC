#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long
#define db double
#define pill pair<int, ll>
#define plli pair<ll, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
 
using namespace std;



const int MAX_N = 2e5 + 5;
const ll mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n, c, m;
pii a[MAX_N];

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        while (!ms.empty() && *ms.begin() <= a[i].fi) {
            ms.erase(ms.begin());
        }
        if ((int) ms.size() == c) {
            if (*(--ms.end()) > a[i].se) {
                ms.erase(--ms.end());
                ms.insert(a[i].se);
            }
        }
        else {
            ans++;
            ms.insert(a[i].se);
        }
    }

    cout << ans;

    return 0;
}
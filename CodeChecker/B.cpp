#include <bits/stdc++.h>

using namespace std;

const int N = 1505;

int BIT[N][N];
int a[N], b[N];
int n, m, SIZE;

void update(int i, int y, int v) {
    for (; i <= n; i += i & -i) for (int j = y; j <= SIZE; j += j & -j)
        BIT[i][j] = max(BIT[i][j], v);
}

int getMax(int i, int y) {
    int ans = 0;
    for (; i; i -= i & -i) for (int j = y; j; j -= j & -j)
        ans = max(ans, BIT[i][j]);
    return ans;
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector<int> V (b + 1, b + 1 + n);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    SIZE = V.size();
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= SIZE; ++j)
        BIT[i][j] = 0;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        vector<pair<pair<int, int>, int> > buffer;
        for (int j = 1; j <= n; ++j) if (a[i] == b[j]) {
            int value = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
            int half = int(upper_bound(V.begin(), V.end(), a[i] >> 1) - V.begin());
            int cur = getMax(j - 1, half) + 1;
            ans = max(ans, cur);
            buffer.push_back(make_pair(make_pair(j, value), cur));
        }
        while (!buffer.empty()) {
            update(buffer.back().first.first, buffer.back().first.second, buffer.back().second);
            buffer.pop_back();
        }
    }
    cout << ans << '\n';
}

 int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    int nTest; cin >> nTest;
    while (nTest--) solve();
    return 0;
 }

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define fi first
#define se second
#define int long long

typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, int> plli;
typedef pair<ll, ll> pll;

const int MAX_N = 5e3 + 5;

int n, q;
bool a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];

int getSum(int x, int y, int u, int v) {
    return b[u][v] - b[x - 1][v] - b[u][y - 1] + b[x - 1][y - 1];
}

int cal() {
    int ans = 0;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            for (int i = r; i <= n; i++) {
                for (int j = c; j <= n; j++) {
                    if (!getSum(i - r + 1, j - c + 1, i, j)) {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

void update() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[i][j] + b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("RECTCNT.inp", "r", stdin);
    freopen("RECTCNT.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j + 1] = (s[j] == '1');
        }
    }

    update();
    cout << cal() << '\n';
    while (q--) {
        int u, v;
        cin >> u >> v;
        a[u][v] ^= 1;
        update();
        cout << cal() << '\n';
    }
}

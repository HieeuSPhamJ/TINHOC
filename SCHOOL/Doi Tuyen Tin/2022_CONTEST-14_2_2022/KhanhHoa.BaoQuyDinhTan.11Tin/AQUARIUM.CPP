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

const int MAX_N = 2e3 + 5;
const int inf = 1e18 + 1;

int n, m;
int a[MAX_N];
int sum[MAX_N];
int dp[MAX_N][MAX_N];

void minimize(int &a, const int& b) {
    a = min(a, b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("AQUARIUM.inp", "r", stdin);
    freopen("AQUARIUM.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int gr = 1; gr <= m; gr++) {
            for (int j = i - 1; ~j; j--) {
                minimize(dp[i][gr], dp[j][gr - 1] + (sum[i] - sum[j]) * (i - j));
            }
        }
    }

    cout << dp[n][m];
    return 0;
}

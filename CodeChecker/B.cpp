#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 2e4 + 5;
const int MAX_M = 1e3 + 5;
const int inf = 1e18;

int n, m;
pii bus[MAX_N];
pii student[MAX_M];
int prefMinBus[MAX_N][MAX_M];
int pref[MAX_M];
int dist[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
freopen("input.inp", "r", stdin);
freopen("B.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bus[i].fi >> bus[i].se;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> student[i].fi >> student[i].se;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = (student[j].fi > bus[i].fi ? (student[j].fi - bus[i].fi) * student[j].se : 0) + dist[i][j - 1];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            prefMinBus[i][j] = inf;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0;
    for (int j = 1; j <= m; j++) {
        pref[j] = dp[0][j] = dp[0][j - 1] + student[j].fi * student[j].se;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;

        if (!i) {
            for (int j = 0; j < m; j++) {
                // di bus
                if (student[j + 1].fi >= bus[i + 1].fi) {
                    minimize(prefMinBus[i][j], dp[i][j] - dist[i + 1][j]);
                }
            }
            continue;
        }

        int prefMin = 0;
        for (int j = 1; j <= m; j++) {
            minimize(prefMinBus[i - 1][j], prefMinBus[i - 1][j - 1]);

            // tinh dp
            minimize(dp[i][j], dp[i - 1][j]);

            // th di bus
            if (student[j].fi >= bus[i].fi) {
                minimize(dp[i][j], prefMinBus[i - 1][j - 1] + bus[i].se + dist[i][j]);
            }

            // th di bo
            minimize(dp[i][j], prefMin + pref[j]);

            // update
            // di bo
            minimize(prefMin, dp[i - 1][j] - pref[j]);
        }

        for (int j = 0; j < m; j++) {
            // di bus
            if (student[j + 1].fi >= bus[i + 1].fi) {
                minimize(prefMinBus[i][j], dp[i][j] - dist[i + 1][j]);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int ans = inf;
        for (int j = 0; j <= n; j++) {
            minimize(ans, dp[j][i]);
        }
        cout << ans << ' ';
    }

    return 0;
}

/*

N xe bus
M hoc sinh

N + M diem tam 2e4 + 1e3

Co N canh tu N xe bus
Co M canh tu M hs ve 1
    + M * N canh tu M hs ve cac tram xe

dp[i][j] = cost nho nhat de dua j hoc sinh ve, su dung 1 vai xe bus tu 1 -> i



// th di bus
dp[i][j] = min(dp[i - 1][j], dp[i - 1][z - 1] + cost)

1 <= z <= j

cost = dist[i][j] - dist[i][z - 1] + c[i]

// th di bo nua



Tuesday, 10 October 2023
14:17:31
*/
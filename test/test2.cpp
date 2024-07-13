#include <bits/stdc++.h>

using namespace std;

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

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

const int MAX_N = 2e7 + 10;
const int mod = 1e9 + 7;
const int inv2 = 500000004;

void add(int &a, const int& b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(const int& a, const int& b) {
    return 1ll * a * b % mod;
}

ll n;
bool p[MAX_N];
int pri[MAX_N];
int phi[MAX_N];
map<ll, int> dp;

int solve(ll m){
    if (m >= MAX_N) {
        if (dp[m]) {
            return dp[m];
        }

        int ret = mul(m, mul(m + 1, inv2));

        for(ll l = 2, r; l <= m; l = r + 1) {
            r = m / (m / l);
            add(ret, mod - mul(solve(m / l), r - l + 1));
        }

        return dp[m] = ret;
    }
    else {
        return phi[m];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    phi[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        if (!p[i]) {
            phi[i] = i;
            pri[++pri[0]] = i;
            phi[i]--;
        }
        for(int j = 1; i * pri[j] < MAX_N && j <= pri[0]; j++) {
            p[pri[j] * i] = true;
            if (i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            else {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            }
        }
    }
    for (int i = 2; i < MAX_N; i++) {
        add(phi[i], phi[i - 1]);
    }

    int ans = 0;

    for (ll x = 2; x <= n; x <<= 1) {
        add(ans, solve(n / x));
        add(ans, mod - 1);
    }    

    cout << ans;

    return 0;
}

/*


Saturday, 08 June 2024
10:14:08
*/
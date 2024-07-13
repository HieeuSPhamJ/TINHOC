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

const int MAX_N = 19 + 5;
const int mod = 1e9 + 7;
const int base = 19;

int cnt[MAX_N][MAX_N][3];
int sum[MAX_N][MAX_N][3];
int sum_sqr[MAX_N][MAX_N][3];

void add(int &a, const int& b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

pii sol(int n) {
    if (!n) return {0, 0};

    vector<int> a;
    while (n) {
        a.pb(n % 10);
        n /= 10;
    }
    reverse(all(a));
    n = (int) a.size();
    int m = n / 2;

    for (int i = 0; i < n; i++) {
        for (int diff = 0; diff <= m; diff++) {
            for (int state = 0; state < 3; state++) {
                cnt[i][diff][state] = sum[i][diff][state] = sum_sqr[i][diff][state] = 0;
            }
        }
    }

    // add so dau tien
    for (int j = 2; j <= 8; j += 2) {
        int state = 1;
        if (j < a[0]) {
            state = 0;
        }
        if (j > a[0]) {
            state = 2;
        }

        cnt[0][1][state]++;
        sum[0][1][state] += j;
        sum_sqr[0][1][state] += j * j;
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int diff = 0; diff <= m; diff++) {
            for (int state = 0; state < 3; state++) {
                if (!cnt[i][diff][state]) continue;

                for (int j = 0; j <= 9; j++) {
                    int newDiff = diff + (j & 1 ? -1 : 1);
                    if (newDiff < 0 || newDiff > m) {
                        continue;
                    }

                    int newState = state;
                    if (state == 1) {
                        if (j > a[i + 1]) {
                            newState = 2;
                        }
                        if (j < a[i + 1]) {
                            newState = 0;
                        }
                    }

                    int x = 1ll * cnt[i][diff][state] * j % mod;

                    add(cnt[i + 1][newDiff][newState], cnt[i][diff][state]);
                    add(sum[i + 1][newDiff][newState], 10ll * sum[i][diff][state] % mod);
                    add(sum[i + 1][newDiff][newState], x);
                    add(sum_sqr[i + 1][newDiff][newState], 100ll * sum_sqr[i][diff][state] % mod);
                    add(sum_sqr[i + 1][newDiff][newState], 1ll * j * (20ll * sum[i][diff][state] % mod) % mod);
                    add(sum_sqr[i + 1][newDiff][newState], 1ll * j * x % mod);
                }
            }
        }
    }

    pii ans = {0, 0};

    for (int i = 0; i < n; i++) {
        // diff = 0;
        for (int state = 0; state <= (i == n - 1 ? 1 : 2); state++) {
            add(ans.fi, cnt[i][0][state]);
            add(ans.se, sum_sqr[i][0][state]);
        }
    }

    return ans;
}

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCase;
    cin >> numCase;
    for (int testCase = 1; testCase <= numCase; testCase++) {
        int a, b;
        cin >> a >> b;

        pii sol1 = sol(b);
        pii sol2 = sol(a - 1);

        add(sol1.fi, mod - sol2.fi);
        add(sol1.se, mod - sol2.se);

        cout << sol1.fi << ' ' << sol1.se << '\n';
    }

    return 0;
}

/*


Saturday, 08 June 2024
10:53:47
*/
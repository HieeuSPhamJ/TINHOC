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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 5e4 + 5;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int base1 = 256;
const int base2 = 26 + rd() % 500 + 1;

int n, d;
string s;
pii POW[MAX_N];
pii HASH[MAX_N];
int ans[MAX_N];
unordered_map<int, int> cnt;

pii hashing(const pii& a, const char& h) {
    return {(1ll * a.fi * base1 + h - '0' + 1) % mod1, (1ll * a.se * base2 + h - '0' + 1) % mod2};
}

pii getHash(int l, int r) {
    if (l > r) return {0, 0};
    return {(1ll * HASH[r].fi - 1ll * HASH[l - 1].fi * POW[r - l + 1].fi + 1ll * mod1 * mod1) % mod1, (1ll * HASH[r].se - 1ll * HASH[l - 1].se * POW[r - l + 1].se + 1ll * mod2 * mod2) % mod2};
}

int decode(const pii& a) {
    return (a.fi << 30) + a.se;
}

pii mul(const pii &a, const pii& b) {
    return {1ll * a.fi * b.fi % mod1, 1ll * a.se * b.se % mod2};
}

pii sum(const pii &a, const pii& b) {
    return {(a.fi + b.fi) % mod1, (a.se + b.se) % mod2};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("KSTRING.inp", "r", stdin);
    freopen("KSTRING.out", "w", stdout);

    cin >> n >> d;
    cin >> s;

    POW[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        POW[i] = {1ll * POW[i - 1].fi * base1 % mod1, 1ll * POW[i - 1].se * base2 % mod2};
        HASH[i] = hashing(HASH[i - 1], s[i - 1]);
    }

    if (d == 1) {
        for (int k = 1; k <= n; k++) {
            cnt.clear();
            for (int i = k; i <= n; i += k) {
                for (int j = i - k + 1; j <= i; j++) {
                    for (char h = 'a'; h <= 'z'; h++) {
                        if (h == s[j - 1]) continue;
                        pii tmp = hashing(getHash(i - k + 1, j - 1), h);
                        tmp = sum(mul(tmp, POW[i - j]), getHash(j + 1, i));
                        int x = decode(tmp);
                        ans[k] += cnt[x];
                    }
                }
                int tmp = decode(getHash(i - k + 1, i));
                ans[k] += cnt[tmp];
                cnt[tmp]++;
            }
        }
    }
    else {
        for (int k = 1; k <= n; k++) {
            cnt.clear();
            for (int i = k; i <= n; i += k) {
                int tmp = decode(getHash(i - k + 1, i));
                ans[k] += cnt[tmp];
                cnt[tmp]++;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
}

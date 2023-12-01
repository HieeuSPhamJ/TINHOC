#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <climits>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define RESET(a, v) memset((a), (v), sizeof((a)))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>

const int N = 100005;

using namespace std;

vector<II> e;
VI a[N];
int low[N], num[N], cnt[N], par[N], sz[N];
bool isBridge[N];
int n, m, timer, cntBridge, cc;

void dfs(int u) {
    num[u] = ++timer; low[u] = INT_MAX; cnt[cc]++; sz[u] = 1;
    TR(v, a[u]) if (*v != par[u]) {
        if (num[*v]) low[u] = min(low[u], num[*v]);
        else {
            par[*v] = u;
            dfs(*v);
            low[u] = min(low[u], low[*v]);
            sz[u] += sz[*v];
        }
    }
    if (low[u] >= num[u] && par[u])
        cntBridge += isBridge[u] = 1;
}

LL solve() {
    if (cc > 2) return 0;
    if (cc == 2) return (LL)cnt[1] * cnt[2] * (m - cntBridge);
    LL ans = 0, maxE = (LL)n * (n - 1) / 2;
    TR(it, e) {
        int u = it -> X;
        int v = it -> Y;
        if (num[u] > num[v]) swap(u, v);
        if (par[v] == u && isBridge[v])
            ans += (LL)sz[v] * (sz[1] - sz[v]) - 1;
        else
            ans += maxE - m;
    }
    return ans;
}

int main() {
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int u, v;
    FOR(i, 0, m) {
        cin >> u >> v;
        a[u].PB(v); a[v].PB(u);
        e.PB(MP(u, v));
    }
    REP(i, 1, n) if (num[i] == 0) {
        cc++;
        dfs(i);
    }
    cout << solve();
    return 0;
}

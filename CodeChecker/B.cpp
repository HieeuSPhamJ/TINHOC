#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define REPD(i, a, b) for(int i = (a); i >= (b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define VI vector<int>
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define II pair<int, int>
#define X first
#define Y second
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int((a).size()))

const int N = 2010;

using namespace std;

typedef pair<LL, LL> point;

struct polygon {
    vector<point> v;
    polygon() {v.clear();}
    LL area;
    int color;
    bool operator < (const polygon &that) const {
        return area < that.area;
    }
} poly[N];

int m, k;
int cnt[N];

int main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> m >> k;
    FOR(i, 0, m) {
        int n, x, y;
        cin >> n >> poly[i].color >> poly[i].area;

    }
    sort(poly, poly + m);
    LL ans = 0;
    FOR(i, 0, m) {
        FOR(j, 0, m) cnt[j] = 0;
        II mode (0, 0);
        FOR(j, i, m) {
            cnt[poly[j].color]++;
            if (cnt[poly[j].color] > mode.Y)
                mode = MP(poly[j].color, cnt[poly[j].color]);
            if (mode.Y >= (j - i + 1) - k)
                ans = max(ans, poly[j].area - (i > 0 ? poly[i - 1].area : 0));
        }
    }
    cout << ans / 2;
    if (ans & 1) cout << ".5"; else cout << ".0";
    return 0;
}

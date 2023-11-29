#include <bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define mp make_pair
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;

struct point_t {
  int x, y;
  point_t(int _x, int _y) {
    x = _x;
    y = _y;
  }
  point_t() {}
  point_t operator - (const point_t &oth) const {
    return point_t(x - oth.x, y - oth.y);
  }
};

struct line_t {
  int a, b;
  long long c;
  line_t(int _a, int _b, long long _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  line_t() {}
};

long long cross(point_t a, point_t b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

point_t vt(point_t a, point_t b) {
  return point_t(a.y - b.y, b.x - a.x);
}

line_t line(point_t a, point_t b) {
  point_t w = vt(a, b);
  return line_t(w.x, w.y, cross(a, b));
}
const int N = 1e6 + 7;

int n, height;
point_t a[N];
int st[N];
int lef[N];
int rig[N];

signed main() {

freopen("Leonui.INP", "r", stdin);
freopen("Leonui.OUT", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> height;
  for (int i = 1; i <= n; i ++) {
    cin >> a[i].x >> a[i].y;
  }

  auto ccw = [&](point_t a, point_t b, point_t c) {
    return 1LL * a.x * (c.y - b.y)
        +  1LL * b.x * (a.y - c.y)
        +  1LL * c.x * (b.y - a.y);
  };

  int m = 0;
  st[++ m] = 1;
  for (int i = 2; i < n; i ++) {
    while (m > 1 && ccw(a[st[m - 1]], a[st[m]], a[i]) <= 0) {
      m --;
    }
    if (i & 1) {
      lef[i] = st[m];
    }
    st[++ m] = i;
  }
  m = 0;
  st[++ m] = n;
  for (int i = n - 1; i > 1; i --) {
    while (m > 1 && ccw(a[st[m - 1]], a[st[m]], a[i]) >= 0) {
      m --;
    }
    if (i & 1) {
      rig[i] = st[m];
    }
    st[++ m] = i;
  }

  #define pii pair<long long, int>
  auto get = [&](line_t ln) -> pii {
    return mp((-ln.c - 1LL * ln.b * height), ln.a);
  };
  vector<pair<pii, pii>> seg;
  for (int i = 3; i < n; i += 2) {  
    line_t l(line(a[i], a[lef[i]]));
    line_t r(line(a[i], a[rig[i]]));
    seg.emplace_back(get(l), get(r));
  }
  sort(all(seg), [&](pair<pii, pii> l, pair<pii, pii> r) {
    return l.se.fi * r.se.se < l.se.se * r.se.fi;
  });
  int res = 0;
  for (int i = 0, j = 0; i < (int) seg.size(); i ++) {
    j = i + 1;
    res ++;
    while (j < (int) seg.size() && seg[j].fi.fi * seg[i].se.se <= seg[i].se.fi * seg[j].fi.se) {
      j ++;
    }
    i = j - 1;
  }
  cout << res;
  return 0;
}
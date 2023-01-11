#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
vector<int> g[N];
int depth[N], parent[N], max_pos[N];
int pos[N], heavy[N], head[N];
int cur_pos;

long long tree[4 * N + 1], lazy[4 * N + 1];
int treesize;

int dfs(int v) {
   int size = 1;
   int max_size = 0;
   for (auto to : g[v]) {
      if (to == parent[v]) continue;
      parent[to] = v;
      depth[to] = depth[v] + 1;
      int c_size = dfs(to);
      size += c_size;
      if (c_size > max_size) {
         max_size = c_size;
         heavy[v] = to;
      }
   }
   return size;
}

void decompose(int v, int h) {
   head[v] = h;
   pos[v] = cur_pos++;
   max_pos[v] = pos[v];
   if (heavy[v] != -1) {
      decompose(heavy[v], h);
      max_pos[v] = max(max_pos[v], max_pos[heavy[v]]);
   }
   for (auto to : g[v]) {
      if (to == parent[v] || to == heavy[v]) continue;
      decompose(to, to);
      max_pos[v] = max(max_pos[v], max_pos[to]);
   }
}

void prepare(int n) {
   fill(heavy, heavy + n, -1);
   
   parent[0] = -1;
   depth[0] = 0;
   dfs(0);

   cur_pos = 0;
   decompose(0, 0);
}

void push(int v, int vl, int vr) {
   if (lazy[v] == 0) return;
   tree[v] += lazy[v];
   if (vl != vr) {
      lazy[v << 1] += lazy[v];
      lazy[v << 1 | 1] += lazy[v];
   }
   lazy[v] = 0;
}

void seg_update(int l, int r, int val, int v = 1, int vl = 0, int vr = treesize - 1) {
   push(v, vl, vr);
   if (l > vr || vl > r) return;
   if (l <= vl && vr <= r) {
      lazy[v] += val;
      push(v, vl, vr);
      return;
   }
   int vm = (vl + vr) >> 1;
   seg_update(l, r, val, v << 1, vl, vm);
   seg_update(l, r, val, v << 1 | 1, vm + 1, vr);
   tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
}

long long seg_query(int l, int r, int v = 1, int vl = 0, int vr = treesize - 1) {
   push(v, vl, vr);
   if (l > vr || vl > r) return LONG_LONG_MIN;
   if (l <= vl && vr <= r) return tree[v];
   int vm = (vl + vr) >> 1;
   long long g1 = seg_query(l, r, v << 1, vl, vm);
   long long g2 = seg_query(l, r, v << 1 | 1, vm + 1, vr);
   return max(g1, g2);
}

long long query(int a, int b) {
   long long res = LONG_LONG_MIN;
   while (head[a] != head[b]) {
      if (depth[head[a]] > depth[head[b]])
         swap(a, b);
      res = max(res, seg_query(pos[head[b]], pos[b]));
      b = parent[head[b]];
   }
   if (depth[a] > depth[b])
      swap(a, b);
   res = max(res, seg_query(pos[a], pos[b]));
   return res;
}

int main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   treesize = n;
   for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[v].push_back(u);
      g[u].push_back(v);
   }
   prepare(n);
   int q;
   cin >> q;
   while (q --) {
      string t;
      cin >> t;
      if (t == "max") {
         int l, r;
         cin >> l >> r; l--; r--;
         cout << query(l, r) << '\n';
      } else {
         int i, val;
         cin >> i >> val; i--;
         seg_update(pos[i], max_pos[i], val);
      }
   }
   return 0;
}
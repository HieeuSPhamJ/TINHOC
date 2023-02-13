#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int n;
int a[maxN];
int id[maxN];
int en[maxN];
int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[i] = 0;
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] += val;
        lazy[i] += val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1,t2);
}

void update(int l, int r, int v){
    update(1,1,n,l,r,v);
}

int get(int l, int r){
    if (l < 1){
        l = 1;
    }
    if (l > r){
        return 0;
    }
    return get(1,1,n,l,r);
}

int bit[2 * maxN];

void updatePoint(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateBit(int l, int r, int v) {
    updatePoint(l, v);
    updatePoint(r + 1, -v);
}

int getBit(int u) {
    int idx = u, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
vector <int> adj[maxN];
int sz[maxN];
int knup[maxN];
int dep[maxN];
int p[maxN];
int father[maxN][25];
int child[maxN][25];

void getsz(int node, int fa){
    sz[node] = 1;
    p[node] = fa;
    for (auto i: adj[node]){
        if (fa == i){
            continue;
        }
        father[i][0] = node;
        child[node][0] = i;
        dep[i] = dep[node] + 1;
        getsz(i,node);
        sz[node] += sz[i];
    } 
}

int cnt = 1;

void hld(int node, int fa, int top){
    int hc = -1;
    id[node] = cnt++;
    knup[node] = top;
    // cout << node << " " << id[node] << " " << knup[node] << endl;
    for (auto nu: adj[node]){
        if (nu == fa){
            continue;
        }
        if (sz[hc] < sz[nu]){
            hc = nu;
        }
    }
    if (hc != -1){
        hld(hc,node,top);
    }
    for (auto nu: adj[node]){
        if (nu == hc or nu == fa){
            continue;
        }
        hld(nu,node,nu);
    }
    en[node] = cnt - 1;
}

void query(int x, int y, int w){
    int res = 0;
    while(knup[x] != knup[y]){
        if (dep[knup[x]] < dep[knup[y]]){
            swap(x,y);
        }
        // cout << x << " " << y << " | ";
        // cout << id[knup[x]] << " " << id[x] << " " << w << endl;
        update(id[knup[x]], id[x], w);
        x = p[knup[x]];
    }

    if (dep[x] > dep[y]){
        swap(x,y);
    }
    // cout << id[x] << " " << id[y] << " " << w << endl;
    update(id[x], id[y], w);
}

void init(){
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
            child[i][j] = child[child[i][j - 1]][j - 1];
            
        }
    }
}

int LCA(int a, int b){
    if (dep[a] < dep[b]){
        swap(a,b);
    }
    for (int i = log2(dep[a]); i >= 0; i--){
        if (dep[father[father[a][i]][0]] >= dep[b]){
            a = father[a][i];
        }
    }

    if (father[a][0] == b){
        return a;
    }

    a = father[a][0];

    for (int i = log2(dep[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return a;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> n;
    cin >> test;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dep[1] = 1;
    getsz(1,1);
    hld(1,1,1);
    init();

    while(test--){
        int t;
        cin >> t;
        if (t == 0){
            int u, w, d;
            cin >> u >> w >> d;
            // cout << "With: " << u << " " << w << " " << d << endl;
            if (u == 1){
                updateBit(1,d + 1,w);
                continue;
            }
            // cout << dep[u] << endl;
            int top = u;
            for (int i = log2(dep[top]); i >= 0; i--){
                if (dep[u] - dep[father[top][i]] <= d and father[top][i] != 0){
                    top = father[top][i];
                }
            }
            // cout << top << " " << u << " " << w << endl;
            query(top,u,w);

            int down = u;
            for (int i = log2(n); i >= 0; i--){
                if (child[down][i] != 0 and dep[child[down][i]] - dep[u] <= d){
                    // cout << "down" << i << " " << child[down][i] << " " << dep[dep[child[down][i]] - dep[u]] << " " << d << endl;
                    down = child[down][i];

                }
            }
            // cout << down << " " << u << " " << w << endl;
            query(down,u,w);
            // cout << u << " " << u << " " << -w << endl;
            query(u,u,-w);

            if (dep[u] - dep[1] < d){
                int newDep = d - (dep[u] - dep[1]) + 1;
                updateBit(1, newDep, w); 
                // cout << "dep " << 1 << " " << newDep << " " << w << endl; 
                int lmao = LCA(1,u);
                for (int i = log2(n); i >= 0; i--){
                    if (child[lmao][i] != 0 and dep[child[lmao][i]] <= newDep){
                        lmao = child[lmao][i];
                    }
                }           
                // cout << 1 << " " << lmao << " " << -w << endl;
                query(1,lmao,-w);
            }
        }
        else{
            int u;
            cin >> u;
            // cout << "Ans: ";
            cout << get(id[u],id[u]) + getBit(dep[u]) << endl;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << i << " " << id[i] << endl;
    // }

    // cout << LCA(1,2);


    return 0;
}
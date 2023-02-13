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

vector <int> adj[maxN];
int sz[maxN];
int knup[maxN];
int dep[maxN];
int p[maxN];

void getsz(int node, int fa){
    sz[node] = 1;
    p[node] = fa;
    for (auto i: adj[node]){
        if (fa == i){
            continue;
        }
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

int getTree(int x, int y){
    int res = -inf;
    while(knup[x] != knup[y]){
        if (dep[knup[x]] < dep[knup[y]]){
            swap(x,y);
        }
        // cout << x << " " << y << " | ";
        // cout << id[knup[x]] << " " << id[x] << endl;
        res = max(res, get(1,1,n,id[knup[x]], id[x]));
        x = p[knup[x]];
    }

    if (dep[x] > dep[y]){
        swap(x,y);
    }
    // cout << id[x] << " " << id[y] << endl;
    res = max(res, get(1,1,n,id[x], id[y]));
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> n;

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    getsz(1,1);
    hld(1,1,1);
    cin >> test;
    while(test--){
        string t;
        cin >> t;
        if (t == "add"){
            int u, v;
            cin >> u >> v;
            // cout << id[u] << " " << en[u] << " " << v << endl;
            update(1,1,n,id[u],en[u],v);
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << getTree(a,b) << endl;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << id[i] << " " << en[i] << endl;
    // }


    return 0;
}
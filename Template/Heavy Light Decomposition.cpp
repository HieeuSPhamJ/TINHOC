#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
int a[maxN];
int id[maxN];
int seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return max(t1, t2);
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
    update(1,1,n,id[node],a[node]);
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

}

int query(int x, int y){
    int res = 0;
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
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    getsz(1,1);
    hld(1,1,1);

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int u, v;
            cin >> u >> v;
            update(1,1,n,id[u],v);
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << query(a,b) << " ";
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << get(1,1,n,i,i) << " ";
    // }

    // cout << endl;
    
    // cout << query(10,1) << endl;

    // cout << "END" << endl;

    return 0;
}
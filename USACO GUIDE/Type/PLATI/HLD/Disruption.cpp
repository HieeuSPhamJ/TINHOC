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
int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int v = lazy[i];
    if (v == inf){
        return;
    }
    lazy[2 * i] = min(lazy[2 * i], v);
    lazy[2 * i + 1] = min(lazy[2 * i + 1], v);
    seg[2 * i] = min(seg[2 * i], v);
    seg[2 * i + 1] = min(seg[2 * i + 1], v);
    // lazy[i] = inf;
}

void setLazyForce(int i){
    int val = lazy[i];
    if (val == inf){
        return;
    }
    lazy[2 * i] = val;
    lazy[2 * i + 1] = val;
    seg[2 * i] = val;
    seg[2 * i + 1] = val;
    // lazy[i] = inf;
}

void update(int i, int left, int right, int _left, int _right, int val){
    // cout << "!" << left << " " << right << " " << val << endl;
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = min(seg[i],val);
        lazy[i] = min(lazy[i],val);
        // cout << "!" << left << " " << right << " " << seg[i] << endl;
        return;
    }

    setLazy(i);
    int mid = (left + right) / 2;
    
    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void updateForces(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = val;
        lazy[i] = val;
        return;
    }
    setLazyForce(i);
    int mid = (left + right) / 2;

    updateForces(2 * i, left, mid, _left, _right, val);
    updateForces(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}




int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1,t2);
}

vector <int> adj[maxN];
int sz[maxN];
int knup[maxN];
int dep[maxN];
int p[maxN];
int father[maxN][20];

void getsz(int node, int fa){
    sz[node] = 1;
    p[node] = fa;
    father[node][0] = fa;
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
    // update(1,1,n,id[node],id[node],a[node]);
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


void init(){
    dep[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if (dep[a] < dep[b]){
        swap(a,b);
    }
    for (int i = log2(dep[a]); i >= 0; i--){
        if (dep[father[a][i]] >= dep[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(dep[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

void print(){
    for (int i = 1; i <= n; i++){
        int t = get(1,1,n,id[i],id[i]);
        if (t == inf){
            cout << "x ";
            continue;
        }
        cout << t << " ";
    }
    cout << endl;
}

void query(int x, int y, int w){
    cout << "===Test===" << endl;
    int lca = LCA(x,y);
    // cout << x << "-" << y << " " << lca << " " << w << endl;
    int t = get(1,1,n,id[lca],id[lca]);
    while(knup[x] != knup[y]){
        if (dep[knup[x]] < dep[knup[y]]){
            swap(x,y);
        }
        cout << id[knup[x]] << " " << id[x] << " " << w <<endl;
        update(1,1,n,id[knup[x]],id[x],w);
        // print();
        x = p[knup[x]];
    }

    if (dep[x] > dep[y]){
        swap(x,y);
    }
    cout << id[x] << " " << id[y] << " " << w <<endl;
    update(1,1,n,id[x],id[y],w);
    // print();
    cout << id[x] << " " << id[x] << " " << t <<endl;
    updateForces(1,1,n,id[x],id[x],t);
    // print();
}



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> n >> m;
    for (int i = 0; i < maxN; i++){
        seg[i] = inf;
        lazy[i] = inf;
    }
    vector <ii> lists;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        lists.push_back({a,b});
    }

    getsz(1,1);
    hld(1,1,1);
    init();

    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b){
            continue;
        }
        // query(a, b, c);
        // print();
    }


    // for (auto i: lists){
    //     if(dep[i.fi] < dep[i.se]){
    //         swap(i.fi,i.se);
    //     }
    //     // cout << i.fi << " " << id[i.fi] << endl;
    //     cout << get(1,1,n,id[i.fi],id[i.fi]) << endl;
    // }
    // query(1,3,1);
    update(1,1,n,id[1],id[3],1);
    // print();
    updateForces(1,1,n,id[1],id[1],inf);
    // print();

    
    query(3,2,4);
    // update(1,1,n,4,4,4);
    // print();
    // update(1,1,n,1,2,4);
    // print();
    // updateForces(1,1,n,1,1,inf);
    print();
    return 0;
}
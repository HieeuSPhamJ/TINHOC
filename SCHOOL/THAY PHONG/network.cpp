#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;
 
const int maxN = 1e5 + 10;
const int inf = 1e18;
 
int n;
int a[maxN];
int id[maxN];
int seg[maxN * 4];
int lg[maxN];
 
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
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}
 
int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
 
    int mid = (left + right) / 2;
 
    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return min(t1, t2);
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
    for (auto i: adj[node]){
        if (fa == i){
            continue;
        }
        father[i][0] = node;
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
 

void init(){
    dep[0] = -1;
    for (int j = 1; j <= lg[n]; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

ii LCA(int a, int b){
    if (dep[a] < dep[b]){
        swap(a,b);
    }
    for (int i = lg[dep[a]]; i >= 0; i--){
        if (dep[father[a][i]] > dep[b]){
            a = father[a][i];
        }
    }

    if (father[a][0] == b){
        return {father[a][0], a};
    }
    if (dep[a] != dep[b]){
        a = father[a][0];
    }

            // cout << a << " " << b << " " << i << endl;
    for (int i = lg[dep[a]]; father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return {father[a][0],-1};
}

int query(int x, int y){
    int res = inf;
    while(knup[x] != knup[y]){
        if (dep[knup[x]] < dep[knup[y]]){
            swap(x,y);
        }
        // cout << x << " " << y << " | ";
        // cout << id[knup[x]] << " " << id[x] << endl;
        res = min(res, get(1,1,n,id[knup[x]], id[x]));
        x = p[knup[x]];
    }
 
    if (dep[x] > dep[y]){
        swap(x,y);
    }
    res = min(res, get(1,1,n,id[x], id[y]));
    return res;
}
 
int solve(int a, int b){
    ii lca = LCA(a,b);
    // cout << a << " " << b << endl;
    if (get(1,1,n,id[lca.fi], id[lca.fi]) == -inf){
        return -inf;
    }
    if (a == lca.fi){
        swap(a,b);
    }
    return query(a,lca.se);
}

int isdea[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < 4 * maxN; i++){
        seg[i] = inf;
    }
    
    int test;
    cin >> n >> test;
    vector <pair<int,ii>> ls;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ls.push_back({w,{a,b}});
    }
    
    for (int i = 1; i <= n; i++){
        lg[i] = log2(i);
    }
    getsz(1,1);
    hld(1,1,1);
    init();
    // cout << LCA(3,4).fi << endl;
    update(1,1,n,id[1],inf);
    for (auto i: ls){
        int w = i.fi;
        int a = i.se.fi;
        int b = i.se.se;
        if (dep[a] < dep[b]){
            swap(a,b);
        }
        update(1,1,n,id[a],w);
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 2){
            int u;
            cin >> u;
            update(1,1,n,id[u],-inf);
            isdea[u] = 1;
        }
        else{
            int a, b;
            cin >> a >> b;
            if (a == b){
                if (isdea[a]){
                    cout << -1 << endl;
                }
                else{
                    cout << 0 << endl;
                }
                continue;
            }
            int t = 0;
            ii lca = LCA(a,b);
            if (lca.fi == a or lca.fi == b){
                t = solve(a,b);
            }
            else{
                t = min(solve(a,lca.fi), solve(b, lca.fi));
            }
            if (t == -inf){
                cout << -1 << endl;
            }
            else{
                cout << t << endl;
            }
        }
    }
 
 
    return 0;
}
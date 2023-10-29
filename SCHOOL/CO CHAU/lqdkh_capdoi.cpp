#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
vector <int> adj[maxN];
int res = 0;
int seg[maxN * 4];
int sz[maxN];
int en[maxN];
int st[maxN];
int re[maxN];
int cnt = 1;

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
    seg[i] = (seg[2 * i] + seg[2 * i + 1]);
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
    return (t1 + t2);
}

void update(int i, int v){
    update(1,1,n,i,v);
}

int get(int l, int r){
    l = max(l,1ll);
    r = min(r,n);
    if (l > r){
        return 0;
    }
    // if (l != r){
    //     cout << l << " " << r << endl;
    // }
    return get(1,1,n,l,r);
}

void init(int nu, int fa){
    sz[nu] = 1;
    st[nu] = cnt;
    re[cnt] = nu;
    cnt++; 
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        init(i,nu);
        sz[nu] += sz[i];
    }
    en[nu] = cnt - 1;
}

void dfs(int nu, int fa, int keep){
    // cout << "With: " << nu << endl;
    ii bigchild = {-1,-1};
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (sz[i] > bigchild.se){
            bigchild = {i,sz[i]};
        }
    }
    // cout << bigchild.fi << endl;
    for (auto i: adj[nu]){
        if (i == fa or i == bigchild.fi){
            continue;
        }
        dfs(i,nu,0);
    }
    if (bigchild.fi != -1){
        dfs(bigchild.fi, nu, 1);
    }

    for (auto i: adj[nu]){
        if (i == fa or i == bigchild.fi){
            continue;
        }
        for (int x = st[i]; x <= en[i]; x++){
            // cout << "add " << re[x] << endl;
            update(re[x],1);
        }
    }
    // cout << "With: " << nu << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << get(i,i);
    // }
    // cout << endl;
    int t = get(nu - k, nu + k);
    // cout << nu << " " << t << endl;
    res += t;
    update(nu,1);
    // cout << "add " << nu << endl;
    if (keep == 0){ 
        for (int i = st[nu]; i <= en[nu]; i++){
            update(re[i],0);
            // cout << "era " << re[i] << endl;
        }
    }

}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("capdoi.inp", "r")) {
        freopen("capdoi.inp", "r", stdin);
        freopen("capdoi.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(i);
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (s.find(b) != s.end()){
            s.erase(s.find(b));
        }
    }
    int root = *s.begin();
    init(root,root);
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << sz[i] << " " << st[i] << " " << en[i] << endl;
    // }
    dfs(root,root,1);

    cout << res << endl;
    return 0;
}
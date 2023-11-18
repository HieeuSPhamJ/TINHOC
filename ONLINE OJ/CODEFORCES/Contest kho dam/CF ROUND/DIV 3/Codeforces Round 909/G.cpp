#include"bits/stdc++.h"
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

int n;
vector <int> adj[maxN];
int v[maxN];
int bit[maxN];
int sz[maxN];
int st[maxN];
int en[maxN];
int re[maxN];
int cnt = 1;
int ans[maxN];
vector <pair<ii,int>> query[maxN];

void update(int i, int v){
    // bit[i] += v;
    while(i <= n){
        bit[i] += v;
        i += i & (-i);
    }
}

int get(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= i & (-i);
    }
    return res;
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

void dfs(int nu, int fa, int keep = 0){
    ii big = {-1, -1};
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (big.se < sz[i]){
            big = {i, sz[i]};
        }
    }

    for (auto i: adj[nu]){
        if (i == fa or i == big.fi){
            continue;
        }
        dfs(i,nu);
    }

    if (big.fi != -1){
        dfs(big.fi, nu, 1);
    }

    for (auto x: adj[nu]){
        if (x == fa or x == big.fi){
            continue;
        }
        for (int i = st[x]; i <= en[x]; i++){
            update(v[re[i]],1);
            // cout << "add " << re[i] << endl;
        }
    }

    update(v[nu], 1);
    // cout << "With: " << nu << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << get(i) - get(i - 1) << " ";
    // }
    // cout << endl;
    for (auto test: query[nu]){
        // cout << test.se << ":" << test.fi.fi << " " << test.fi.se << endl;
        ans[test.se] = get(test.fi.se) - get(test.fi.fi - 1);
    }

    if (keep == 0){
        for (int i = st[nu]; i <= en[nu]; i++){
            update(v[re[i]],-1);
            // cout << "era " << re[i] << endl;
        }
    }
}

void solve(){
    int test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        query[i].clear();
        bit[i] = 0;
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v[x] = i;
    }

    for (int i = 1; i <= test; i++){
        ans[i] = 0;
        int l, r, x;
        cin >> l >> r >> x;
        query[x].push_back({{l,r}, i});
    }

    init(1,1);

    dfs(1,1);

    for (int i = 1; i <= test; i++){
        if (ans[i]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test; 
    while(test--){
        solve();
    }
    return 0;
}   
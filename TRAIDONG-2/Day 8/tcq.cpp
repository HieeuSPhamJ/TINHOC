#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5e5 + 10;

int n;
int c[maxN];
vector <int> adj[maxN];
int cnt = 1;
int en[maxN];
int st[maxN];
int sz[maxN];
int re[maxN];
int BIT[maxN];
int a[maxN];
int res[maxN];
vector <ii> query[maxN];


void update(int i, int v){
    while(i <= n + 1){
        BIT[i] += v;
        i += (i & (-i));
    }
}

int get(int i){
    i++;
    int res = 0;
    while(i){
        res += BIT[i];
        i -= (i & (-i));
    }
    return res;
}


void add(int i, int v){
    update(a[i] + 1,-1);
    a[i] += v;
    update(a[i] + 1,1);
}

void init(int nu, int fa){
    st[nu] = cnt;
    re[cnt] = nu;
    cnt++;
    sz[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        init(i, nu);
        sz[nu] += sz[i];
    }
    en[nu] = cnt - 1;
}

void dfs(int nu, int fa, int keep = 0){   
    ii big = {-1,0};
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (big.se < sz[i]){
            big = {i, sz[i]};
        }
    }
    // cout << nu << " " << big.fi << endl;
    for (auto i: adj[nu]){
        if (i == fa or i == big.fi){
            continue;
        }
        dfs(i,nu);
    }
    if (big.fi != -1){
        dfs(big.fi,nu,1);
    }

    for (auto x: adj[nu]){
        if (x == fa or x == big.fi){
            continue;
        }
        for (int i = st[x]; i <= en[x]; i++){
            add(c[re[i]], 1);
        }
    }

    add(c[nu],1);
    for (auto i: query[nu]){
        // res[i.se] = 0;
        res[i.se] = get(n) - get(i.fi - 1);
    }
    // cout << "With: " << nu << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if (keep == 0){
        for (int i = st[nu]; i <= en[nu]; i++){
            add(c[re[i]], -1);
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("tcq.inp", "r")) {
        freopen("tcq.inp", "r", stdin);
        freopen("tcq.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(1,1);
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << st[i] << " " << en[i] << " " << sz[i] << endl;
    // }
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++){
        int x, v;
        cin >> x >> v;
        query[x].push_back({v,i});
    }
    for (int i = 1; i <= n; i++){
        update(1,1);
    }
    dfs(1,1);

    // update(3,1);
    // cout << get(1,4) << endl;

    for (int i = 1; i <= test; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
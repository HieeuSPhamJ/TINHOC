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

const int maxN = 3e5 + 10;

vector <int> adj[maxN];
int rt[maxN];
int res[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int sz[maxN];

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        sz[nu] = max(sz[nu], sz[i]); 
    }
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }
    vector <pair<int,ii>> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        if (u == v){
            continue;
        }
        ls.push_back({i,{a,b}});
        // cout << a << " " << b << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
        rt[u] = v;
    }
    int root = 0;
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        sz[x] = 1;
        root = x;
    }

    dfs(root,root);

    for (auto i: ls){
        if (sz[i.se.fi] and sz[i.se.se]){
            res[i.fi] = 1;
        }
    }

    for (int i = 1; i <= m; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e3 + 10;

int n;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN][maxN];

int lvl[maxN];
int father[maxN][20];

void lcadfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        lvl[i] = lvl[nu] + 1;
        father[i][0] = nu;
        lcadfs(i,nu);
    }
}

void initlca(){
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

ii LCA(int a, int b){
    if (lvl[a] < lvl[b]){
        swap(a,b);
    }
    // cout << a << " " << b << endl;
    int ci = a;
    for (int i = log2(lvl[ci]); i >= 0; i--){
        if (lvl[father[ci][i]] > lvl[b]){
            ci = father[ci][i];
            // cout << "!" << a << " " << b << endl;
        }
    }
    a = father[ci][0];
    if (a == b){
        return {a,ci};
    }
    for (int i = log2(lvl[a]); i >= 0; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];  
            // cout << "*" << a << " " << b << endl;
        }
    }
    return {father[a][0], ci};
}

int cal(int u, int v){
    int &res = dp[u][v];
    if (res != -1){
        return res;
    }
    if (u == v){
        res = 1;
        // cout << u << " " << v  << ": " << res << endl;
        return 1;
    }
    if (u == father[v][0] or v == father[u][0]){
        res = 1 + (a[v] == a[u]);
        // cout << u << " " << v  << ": " << res << endl;
        return res;
    }   

    if (lvl[u] < lvl[v]){
        swap(u,v);
    }

    ii lca = LCA(u,v);

    if (lca.fi != v){
        res = max(res, cal(father[u][0], father[v][0]) + 2 * (a[u] == a[v]));
        res = max(res, cal(u, father[v][0]));
        res = max(res, cal(father[u][0], v));
    }
    else{
        res = max(res,cal(father[u][0],v));
        res = max(res,cal(u,lca.se));
        res = max(res,cal(father[u][0],lca.se) + 2 * (a[u] == a[v]));
    }
    
    // cout << u << " " << v  << ": " << res << endl;
    // if (lca.fi != v){
    //     cout << "two way" << endl;
    // }
    // else{
    //     cout << "one way" << endl;
    //     cout << father[u][0] << " " << lca.se << " << endl;
    // }
    return res;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        lvl[i] = 0;
        for (int j = 1; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    lvl[1] = 1;
    lcadfs(1,1);
    initlca();
    int res = 0;
    // res = cal(1,5);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            res = max(res,cal(i,j));
        }
    }
    // cout << "ANS: ";
    cout << res << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "==START TEST==" << endl;
        solve();
        // cout << "==END TEST==" << endl;
    }
    return 0;
}
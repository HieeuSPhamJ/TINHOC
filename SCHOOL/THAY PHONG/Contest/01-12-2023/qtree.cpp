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

int n, test;
int dep[maxN];
int dist[maxN];
int father[maxN][21];
vector <ii> adj[maxN];
int lg[maxN];

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i.se == fa){
            continue;
        }   
        dep[i.se] = dep[nu] + 1;
        dist[i.se] = dist[nu] + i.fi;
        father[i.se][0] = nu;
        dfs(i.se, nu);
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

int LCA(int a, int b){
    if (dep[a] < dep[b]){
        swap(a,b);
    }
    for (int i = lg[dep[a]]; dep[a] != dep[b]; i--){
        if (dep[father[a][i]] >= dep[b]){
            a = father[a][i];
        }
    }
    if (a == b){
        return a;
    }
    for (int i = lg[dep[a]]; i >= 0; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}

int solve(int a, int k){
    k = dep[a] - (k - 1);
    // cout << a << " " << k << endl;
    for (int i = lg[a]; i >= 0; i--){
        if (dep[father[a][i]] >= k){
            a = father[a][i];
            // cout << a << endl;
        }
    }
    return a;
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
    cin >> n >> test;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    for (int i = 1; i <= n; i++){
        lg[i] = log2(i);
    }

    dfs(1,1);
    init();

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int a, b;
            cin >> a >> b;
            int lca = LCA(a,b);
            // cout << lca << " ";
            cout << dist[a] + dist[b] - 2 * dist[lca] << endl;
        }
        else{
            int a, b, k;
            cin >> a >> b >> k;
            int lca = LCA(a,b);
            if (dep[a] - dep[lca] >= k){
                cout << solve(a,k) << endl;
            }
            else{
                k = dep[b] - dep[lca] + 1 - (k - (dep[a] - dep[lca]));
                // cout << "# " << dep[b] - dep[lca] + 1 << " " << k << " " << (dep[a] - dep[lca]) << endl;
                cout << solve(b, k + 1) << endl;
            }
        }
    }
    return 0;
}
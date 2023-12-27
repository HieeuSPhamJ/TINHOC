#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;


bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}


const int maxN = 1e5 + 10;

int n, P, Q, S;
vector <int> adj[maxN];
int father[maxN][20];
int dep[maxN];
int dp[2][maxN];
int co[maxN];

void dfs_lca(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dep[i] = dep[nu] + 1;
        father[i][0] = nu;
        dfs_lca(i,nu);
    }
}

void init(){
    dep[0] = -1;
    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

void dfs_dp(int nu, int fa){
    if (co[nu]){
        dp[0][nu] = 0;
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs_dp(i, nu);
        minimize(dp[0][nu], dp[0][i] + 1);
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
    cin >> n >> P >> Q >> S;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    memset(dp, 0x3f, sizeof(dp));
    dfs_lca(S,S);
    init();

    for (int i = 1; i <= P; i++){
        int x;
        cin >> x;
        co[x] = 1;
    }

    dfs_dp(S,S);
    


    return 0;
}
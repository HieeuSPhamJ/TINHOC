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

const int maxN = 4010;
const int maxW = 5;
const int mod = 1e9 + 7;

int n, test;
vector <int> adj[maxN];
int dp[maxN][maxN];
int st[maxN];
int en[maxN];
int re[maxN];
int a[maxN];
int cnt = 1;

void init(int nu = 1, int fa = 1){
    st[nu] = cnt;
    re[cnt] = nu;
    cnt++;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        init(i, nu);
    }
    en[nu] = cnt - 1; 
}

int CNTLIM = 0;

void dfs(int id = 1){
    if (id > n){
        return;
    }
    int nu = re[id];
    dfs(id + 1);
    for (int j = 0; j <= maxW; j++){
        dp[id][j] = dp[en[nu] + 1][j];
        // dp[id][j] = dp[id + 1][j];
        // cout << "With: " << id << " " << j << ": " << dp[id][j] << endl;
        if (j - a[nu] >= 0){
            dp[id][j] += dp[id + 1][j - a[nu]];
            // cout << dp[id + 1][j - a[nu]] << endl;
        }
        dp[id][j] %= mod;
        // cout << " =>" << dp[id][j] << endl;
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
    cin >> n >> test;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a++;
        b++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    test--;
    int u, v;
    cin >> u >> v;

    for (int j = 0; j <= maxW; j++){
        dp[en[u + 1] + 1][j] = 1;
    }    

    dfs(st[u + 1]);
    
    cout << dp[st[u + 1]][v] - 1 << endl;

    while(test--){
        cin >> u >> v;
        cout << dp[st[u + 1]][v] - 1 << endl;
    }


    return 0;
}
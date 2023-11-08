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

int n, mod;
int dp[maxN][30];
int dp2[maxN][30];
vector <int> adj[maxN];

int sub(int a, int b = 1){
    return (a - b + mod) % mod;
}
int add(int a, int b = 1){
    return (a + b) % mod;
}

void dfs1(int nu, int fa){
    dp[nu][0] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs1(i,nu);
        for (int j = 0; j < mod; j++){
            dp[nu][add(j)] += dp[i][j];
        }
    }
}

void dfs2(int nu, int fa){
    // cout << "With: " << nu << endl;
    // for (int i = 0; i < mod; i++){
    //     cout << dp2[nu][i] << " ";
    // }
    // cout << endl;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }    
        for (int j = 0; j < mod; j++){
            dp2[i][j] = dp2[nu][sub(j)] - dp[i][sub(j,2)] + dp[i][j];
            // cout << i << " " << j << ": " << dp2[nu][sub(j)] << " " << dp[i][sub(j,2)] << " " << dp[i][j] << endl;
        }
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }    
        dfs2(i,nu);
    }
}

/*
1: 2 -
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("dddd.inp", "r")) {
        freopen("dddd.inp", "r", stdin);
        freopen("dddd.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> mod;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,1);
    for (int i = 0; i < mod; i++){
        dp2[1][i] = dp[1][i];
    }
    dfs2(1,1);
    
    for (int i = 1; i <= n; i++){
        cout << dp2[i][0] << " ";
    }
    return 0;
}
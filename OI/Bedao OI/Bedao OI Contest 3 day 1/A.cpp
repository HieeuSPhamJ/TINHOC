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

vector <ii> adj[maxN];

int res;
int dp[2][maxN];
int dps[maxN];
int ins[maxN][26];

void dfs(int nu, int fa){
    dp[0][nu] = 0;
    set <int> s;
    int child = 0;
    for (auto i: adj[nu]){
        if (i.fi == fa){
            continue;
        }
        dfs(i.fi, nu);
        s.insert(i.se);
        child++;
        dp[0][nu] += dp[0][i.fi];
    }
    if (s.size() != child){
        dp[0][nu]++;
    }
    // cout << nu << " " << dp[nu] << endl;

}

int temp[26];

void reroot(int nu, int fa, int la = -1){
    if (nu != fa){
        // cout << "With: " << nu << endl;
        dp[1][fa] = dps[fa] - dp[0][nu];
        for (int i = 0; i <= 25; i++){
            temp[i] = ins[fa][i];
        }
        temp[la]--;
        int ok = 0;
        for (int i = 0; i <= 25; i++){
            if (temp[i] > 1){
                ok = 1;
            }
            // cout << temp[i];
        }
        // cout << endl;
        dp[1][fa] += ok;
        dp[1][nu] = dp[1][fa];
        // cout << "dp1 " << dp[1][nu] << endl;
    }
    for (auto i: adj[nu]){
        ins[nu][i.se]++;
        if (i.fi == fa){
            dps[nu] += dp[1][i.fi];
            continue;
        }
        dps[nu] += dp[0][i.fi];
    }

    // cout << "in:" << endl;
    // for (int i = 0; i <= 25; i++){
    //     cout << ins[nu][i];
    // }
    // cout << endl;

    int ok = 0;
    for (int i = 0; i <= 25; i++){
        if (ins[nu][i] > 1){
            ok = 1;
        }
    }
    // cout << "c: " << dps[nu] << " " << ok << endl;
    if (dps[nu] + ok == 0){
        res++;
    }

    for (auto i: adj[nu]){
        if (i.fi == fa){
            continue;
        }
        reroot(i.fi, nu, i.se);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("trie.inp", "r")) {
        freopen("trie.inp", "r", stdin);
        freopen("trie.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        char w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w - 'a'});
        adj[b].push_back({a,w - 'a'});
    }

    dfs(1,1);
    // res += (dp[0][1] == 0);
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << dp[0][i] << endl;
    // }
    reroot(1,1);
    
    cout << res << endl;
    return 0;
}


/*
1: 1
2: 0
3: 0
4: 0
5: 0
6: 0
7: 1
8: 1
9: 0
10: 0
*/
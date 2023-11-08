#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cac pair<int,pair<ii,ii>>
using namespace std;

const int maxN = 1e6 + 10;

vector <int> adj[maxN];
int p[maxN];
ii dps[maxN];
int dp[maxN];

void insert(ii &s, int v){
    if (s.fi == -1){
        s.fi = v;
    }
    else if (s.se == -1){
        s.se = v;
    }
    else if (v > s.fi){
        s.se = s.fi;
        s.fi = v;
    }
    else if (v > s.se){
        s.se = v;
    }
    if (s.se > s.fi){
        swap(s.fi,s.se);
    }
}

void erase(ii &s, int v){
    if (s.fi == v){
        s.fi = s.se;
        s.se = -1;
    }
    else if (s.se == v){
        s.se = -1;
    }
}

void dfs(int nu, int ne = 0){
    if (ne == 1){
        ii s = dps[p[nu]];
        insert(dps[p[nu]], dp[nu]);
        if (s == dps[p[nu]]){
            return;
        }
    }
    else{
        ii s = dps[p[nu]];
        erase(dps[p[nu]], dp[nu]);
        if (nu != 1){
            dp[nu] = max(dps[nu].fi, dps[nu].se + 1);
        }
        else{
            dp[nu] = max(dps[nu].fi, dps[nu].se);
        }
        insert(dps[p[nu]], dp[nu]);
        if (s == dps[p[nu]]){
            return;
        }
    }
    if (nu != 1){
        dfs(p[nu]);
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("treecoloring.inp", "r")) {
        freopen("treecoloring.inp", "r", stdin);
        freopen("treecoloring.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> n;
    dp[1] = 0;
    dps[1] = {-1,-1};
    for (int i = 2; i <= n + 1; i++){
        cin >> p[i];
        adj[p[i]].push_back(i);
        dp[i] = 1;
        dps[i] = {-1,-1};
        dfs(i,1);
        cout << dp[1] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int n, m;
set <int> dp[maxN];
int mk[maxN];
int c[maxN];

void dfs(int nu, int fa){
    dp[nu].insert(c[nu]);
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        if (dp[nu].size() < dp[i].size()){
            swap(dp[nu], dp[i]);
        }
        for (auto x: dp[i]){
            dp[nu].insert(x);
        }
    }
    if ((int)dp[nu].size() == m){
        mk[nu] = 1;
    }
}

signed main(){
    freopen("scrat.INP", "r", stdin);
    freopen("scrat.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    for (int i = 1; i <= n; i++){
        cout << mk[i];
    }

    return 0;
}
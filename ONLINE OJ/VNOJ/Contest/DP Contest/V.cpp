#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, mod;
vector <int> adj[maxN];
int dp[maxN];

void dfs1(int node, int father){
    dp[node] = 1;
    for (auto nu: adj[node]){
        if (nu == father){
            continue;
        }
        dfs1(nu,node);

        dp[node] *= (dp[nu] + 1);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> mod;
    for (int i = 1; i<= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   
    dfs1(1,1);
    return 0;
}
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

const int maxN = 2e5 + 10;

vector <int> adj[maxN];
int dp[maxN];
int res[maxN];

void dfs(int nu, int fa){
    dp[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[nu] += dp[i];
        res[nu] += res[i];
    }
    res[nu] += dp[nu];
}

signed main(){
    freopen("TOKEN.INP", "r", stdin);
    freopen("TOKEN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1,1);

    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}